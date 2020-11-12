#ifndef HANDLEQMLDATACONTEXT_H
#define HANDLEQMLDATACONTEXT_H

#include "mysql/mysqloper.h"
#include <QtMqtt/qmqttclient.h>

class HandleQMLDataContext
{
public:
    explicit HandleQMLDataContext();
    ~HandleQMLDataContext();
    /*将Order 的数据存入数据库  / 通过mqttclient 发送给服务器 （cooker 客户端）*/
    bool handleQMLServicerOrder(const QString& table,const QString& data);

private:
    /*初始化上下文环境*/
    void initContext();
    void destoryContext();
private:
    /*保存数据 到mysql 的连接*/
    MySqlOper* m_mysql_oper = nullptr;
    /*转发数据到其他设备 的mqtt客户端*/
    QMqttClient * m_mqtt_client = nullptr;
};

#endif // HANDLEQMLDATACONTEXT_H
