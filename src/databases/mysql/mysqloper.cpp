﻿#include "mysqloper.h"
#include "confighelperutil.h"
#include "global.h"
#include "entityenumindex.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QVariantList>


MySqlOper::MySqlOper()
{
    initConfig();
}

MySqlOper::~MySqlOper()
{

}

void MySqlOper::initConfig()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
        m_mysql_db = QSqlDatabase::addDatabase("QMYSQL");
    }
    else
    {
        //初始化 mysql 的私有变量
        m_mysql_db = QSqlDatabase::addDatabase("QMYSQL");
    }


    //获取配置文件中的 数据库的配置信息
    QString db_name  = ConfigHelperUtil::getInstance().getValue("MySqlConfig","database_name");
    QString hostname = ConfigHelperUtil::getInstance().getValue("MySqlConfig","hostname");
    QString port = ConfigHelperUtil::getInstance().getValue("MySqlConfig","port");
    QString username = ConfigHelperUtil::getInstance().getValue("MySqlConfig","username");
    QString password = ConfigHelperUtil::getInstance().getValue("MySqlConfig","password");
    m_mysql_db.setDatabaseName(db_name);
    m_mysql_db.setHostName(hostname);
    m_mysql_db.setUserName(username);
    m_mysql_db.setPassword(password);
    m_mysql_db.setPort(port.toInt());
    //尝试打开该数据库文件
    if ( ! m_mysql_db.open() )
    {
        DEBUG_MYSQL("Error: Failed to connect mysql database\n");
    }
    else
    {
        DEBUG_MYSQL("Success: connect mysql database\n");
    }
}


Entity MySqlOper::getRecord(const QString &table_name, const QString &p_key, const QString &value, const int &flag)
{
    switch (flag)
    {
        default:break;
        case Employ_flag:
        {
            return getEmployerRecord(table_name,p_key,value);
        }
        case Food_flag:
        {

        }
    }
    return Entity();
}



bool  MySqlOper::executeSql(const QString &sql)
{
    static QSqlQuery querySet;
    querySet.clear();
    return querySet.exec(sql);
}

Entity MySqlOper::getEmployerRecord(const QString &table_name, const QString &p_key, const QString &value)
{
    QSqlQuery querySet;
    Entity entity;
    QString sql = "select * from %1 where %2 = %3;";
    sql = sql.arg(table_name).arg(p_key).arg(value);
    DEBUG_MYSQL("sql %s",sql.toStdString().c_str());
    if( querySet.exec(sql))
    {
        if (querySet.first() && querySet.isValid())
        {
            QStringList list;
            list<<querySet.value("id").toString()
                <<querySet.value("profess").toString()
                <<querySet.value("name").toString()
                <<querySet.value("password").toString();
            DEBUG_MYSQL("sql user id %s",list.join(',').toStdString().c_str());
            entity.setData(list);
        }
    }
    else
    {
        DEBUG_MYSQL("exec error %s",querySet.lastError().text().toStdString().c_str());
    }


    return entity;
}