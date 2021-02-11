#include "handleqmldatacontext.h"
#include <QUuid>
#include <QDateTime>
#include <QtWidgets/QMessageBox>
#include "../om_common/utils/confighelperutil/confighelperutil.h"
#include "../om_common/commoninc/debugdefine.h"
#include "../om_databases/mysql/mysqloper.h"


HandleQMLDataContext::HandleQMLDataContext()
{
    this->m_bruning = false;
    initContext();
}

HandleQMLDataContext::~HandleQMLDataContext()
{
    destoryContext();
}

bool HandleQMLDataContext::handleQMLServicerOrder(const QString &table, const QString &data)
{
    if(!m_bruning)
    {
        initEnvConnect();
        m_bruning = true;
    }
    QString order_str = QUuid::createUuid().toString();
    order_str += "`"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
    order_str += "`"+table;
    order_str += "`"+data;
    QString cooker_top = ConfigHelperUtil::getInstance()->getValue("MQTTConfig","cook_topic");

    if (m_mqtt_client->publish(cooker_top,order_str.toLatin1()) == -1)
    {
        DEBUG_CONNECT("can not publish the message topic %s",cooker_top.toStdString().c_str());
        return false;
    }
    return true;
}

void HandleQMLDataContext::slotMqttDoConnected()
{
     DEBUG_CONNECT("Connected to addr: %s\t successfully",m_mqtt_client->hostname().toStdString().c_str());
}

void HandleQMLDataContext::slotMqttBrokerDisconnected()
{
    DEBUG_CONNECT("disConnected to addr: %s\t",m_mqtt_client->hostname().toStdString().c_str());
}

void HandleQMLDataContext::slotMqttStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_mqtt_client->state())
                    + QLatin1Char('\n');
    DEBUG_CONNECT("mqttclient state: %s\t",content.toStdString().c_str());
}

void HandleQMLDataContext::slotMqttMessageRecvied(const QByteArray &message, const QMqttTopicName &topic)
{

}


/**
* @brief:  初始化 成员变量 并申请内存
* @param： void
* @return: void
* @date: 2020-11-10
*/
void HandleQMLDataContext::initContext()
{
    if(nullptr == this->m_mysql_oper)
    {
        //this->m_mysql_oper = MySqlOper::getInstance();
    }
    if(nullptr == this->m_mqtt_client)
    {
        this->m_mqtt_client = new QMqttClient();

        QString hostname = ConfigHelperUtil::getInstance()->getValue("MQTTConfig","cook_topic");
        QString port = ConfigHelperUtil::getInstance()->getValue("MQTTConfig","port");
        QString username = ConfigHelperUtil::getInstance()->getValue("MQTTConfig","username");
        QString password = ConfigHelperUtil::getInstance()->getValue("MQTTConfig","password");
        this->m_mqtt_client->setHostname(hostname);
        this->m_mqtt_client->setPort(port.toUShort());
        this->m_mqtt_client->setUsername(username);
        this->m_mqtt_client->setPassword(password);
    }
}

void HandleQMLDataContext::initEnvConnect()
{
    connect(m_mqtt_client, &QMqttClient::stateChanged, this, &HandleQMLDataContext::slotMqttStateChange);
    connect(m_mqtt_client, &QMqttClient::disconnected, this, &HandleQMLDataContext::slotMqttBrokerDisconnected);
    connect(m_mqtt_client,&QMqttClient::connected,this,&HandleQMLDataContext::slotMqttDoConnected);

    connect(m_mqtt_client,&QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic){
        this->slotMqttMessageRecvied(message,topic);
    });
    /*连接mqtt server */
    this->m_mqtt_client->connectToHost();
}

/**
* @brief: 释放上下文资源
* @param：
* @return: void
* @date: 2020-11-14
*/
void HandleQMLDataContext::destoryContext()
{
    if(nullptr != this->m_mysql_oper)
    {
        this->m_mysql_oper  = nullptr;
    }
    if(nullptr != this->m_mqtt_client)
    {
        this->m_mqtt_client->disconnectFromHost();
        delete this->m_mqtt_client ;
        this->m_mqtt_client = nullptr;
    }
}
