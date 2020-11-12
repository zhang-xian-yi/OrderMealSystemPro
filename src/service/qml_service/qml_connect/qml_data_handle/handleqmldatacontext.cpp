#include "handleqmldatacontext.h"
#include <QUuid>
#include <QDateTime>

HandleQMLDataContext::HandleQMLDataContext()
{
    initContext();
}

HandleQMLDataContext::~HandleQMLDataContext()
{
    destoryContext();
}

bool HandleQMLDataContext::handleQMLServicerOrder(const QString &table, const QString &data)
{
    QString order_str = QUuid::createUuid().toString();
    order_str += "#"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
    order_str += "#"+table;
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
        this->m_mysql_oper = MySqlOper::getInstance();
    }
    if(nullptr == this->m_mqtt_client)
    {
        this->m_mqtt_client = new QMqttClient();
    }
}

void HandleQMLDataContext::destoryContext()
{
    if(nullptr != this->m_mysql_oper)
    {
        this->m_mysql_oper  = nullptr;
    }
    if(nullptr != this->m_mqtt_client)
    {
        delete this->m_mqtt_client ;
        this->m_mqtt_client = nullptr;
    }
}
