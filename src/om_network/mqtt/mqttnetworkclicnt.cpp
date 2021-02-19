#include "mqttnetworkclicnt.h"
//mqtt 的头文件
#include "./mqttinc/qmqttclient.h"
#include "./mqttinc/qmqtttopicname.h"
//common
#include "../om_common/commoninc/debugdefine.h"
#include "../om_common/datastruct/datastructs.h"

MqttNetworkClicnt::MqttNetworkClicnt()
{
    m_pClient = new QMqttClient;
}

MqttNetworkClicnt::MqttNetworkClicnt(const ParameterData &config)
{
    startClient(config);
}
/**
* @brief: 释放资源
* @param：
* @return:
* @date: 2021-02-18
*/
MqttNetworkClicnt::~MqttNetworkClicnt()
{
    if(nullptr != m_pClient)
    {
        m_pClient->disconnectFromHost();
        delete m_pClient;
        m_pClient = nullptr;
    }
}
/**
* @brief: 启动 链接网络的客户端 通过配置文件现实
* @param：
* @return:
* @date: 2021-02-18
*/
bool MqttNetworkClicnt::startClient(const ParameterData &config)
{
    if (m_pClient->state() == QMqttClient::Disconnected)
    {
        m_pClient->setHostname(config.getValue("hostname"));
        m_pClient->setPort(config.getValue("port").toUShort());
        m_pClient->setUsername(config.getValue("username"));
        m_pClient->setPassword(config.getValue("password"));
        m_pClient->connectToHost();
        initConnects();
    }
    return m_pClient->state() == QMqttClient::Connected;
}
/**
* @brief: 发布消息
* @param：
* @return:
* @date: 2021-02-18
*/
bool MqttNetworkClicnt::publishMessage(const ParameterData &message)
{
    QString topic = message.getValue("topic");
    QByteArray msg = message.getValue("msg").toLocal8Bit();
    if (m_pClient->publish(topic, msg) == -1)
    {
        return false;
    }
    return true;
}
/**
* @brief: 订阅 一份消息
* @param：
* @return:
* @date: 2021-02-18
*/
bool MqttNetworkClicnt::subscribeMessage(const ParameterData &message)
{
    QString topic = message.getValue("topic");
    auto subscription = m_pClient->subscribe(topic);
    if( ! subscription)
    {
        return false;
    }
    return true;
}
/**
* @brief: mqttclient 完成对 服务器的链接
* @param：
* @return:
* @date: 2021-02-18
*/
void MqttNetworkClicnt::doConnected()
{
    DEBUG_CONNECT_TRACE("connected mqttsercer zhangxianyi");
}
/**
* @brief: 消息接受
* @param：
* @return:
* @date: 2021-02-18
*/
void MqttNetworkClicnt::doMessageRecvied(const QByteArray &message, const QMqttTopicName &topic)
{
    DEBUG_CONNECT_TRACE("topic:%s\nmessage:%s",topic.name().toStdString().c_str(),message.toStdString().c_str());
}
/**
* @brief: 链接状态改变
* @param：
* @return:
* @date: 2021-02-18
*/
void MqttNetworkClicnt::updateStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change:")
                    + QString::number(m_pClient->state())
                    + QLatin1Char('\n');
    DEBUG_CONNECT_TRACE("connect state %s",content.toStdString().c_str());
}
/**
* @brief: 初始化 信号槽链接关系
* @param：
* @return:
* @date: 2021-02-18
*/
void MqttNetworkClicnt::initConnects()
{
    connect(m_pClient,&QMqttClient::connected,this,&MqttNetworkClicnt::doConnected);
    connect(m_pClient, &QMqttClient::stateChanged, this, &MqttNetworkClicnt::updateStateChange);
    connect(m_pClient,&QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic){
            this->doMessageRecvied(message,topic);
        });
}


