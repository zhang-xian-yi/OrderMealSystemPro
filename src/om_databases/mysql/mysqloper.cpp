#include "mysqloper.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QVariantList>
#include <QDateTime>

#include "../om_common/utils/confighelperutil/confighelperutil.h"
#include "../om_common/commoninc/debugdefine.h"
#include "../om_common/commoninc/commoninterface.h"
#include "../om_common/datastruct/datastructs.h"
#include "../om_common/datastruct/databasesentity.h"
namespace DatabaseSpace
{
enum RecordFlag
{
    E_EMPLOYER_ONE_RECORED = 0,
};
}

MySqlOper::~MySqlOper()
{
    if (m_mysql_db.isValid())
    {
        if (m_mysql_db.isOpen())
        {
            m_mysql_db.close();
        }
        m_mysql_db = QSqlDatabase::database("", false);
        //QSqlDatabase::removeDatabase(m_connect_name);
    }
}


MySqlOper::MySqlOper(const BaseStruct *pPara)
{
    const ParameterData* para = dynamic_cast<const ParameterData*>(pPara);
    if(nullptr != para)
    {
        initConfig(para);
    }

}

QList<Entity> MySqlOper::getFoodListByType(const QString &type)
{
    QSqlQuery querySet(m_mysql_db);
    QList<Entity> result_list;
    result_list.clear();
    /*sql 语句 加上 英文 ；*/
    QString sql = "call getFoodListByType('%1');";
    sql = sql.arg(type);
    DEBUG_MYSQL("call procedure sql %s",sql.toStdString().c_str());
    if( querySet.exec(sql) )
    {
        while (querySet.next())
        {
            QStringList list;
            list<<querySet.value("name").toString()
                <<querySet.value("price").toString()
                <<querySet.value("detail").toString()
                <<querySet.value("imgurl").toString();
            Entity entity(list);
            result_list.append(entity);
        }
    }
    else
    {
        DEBUG_MYSQL("exec error %s",querySet.lastError().text().toStdString().c_str());
    }
    return result_list;
}

/**
* @brief: 初始化配置文件参数
* @param：
* @return:
* @date: 2021-01-18
*/
void MySqlOper::initConfig(const ParameterData *pPara)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    m_connect_name = "qt_sql_default_connect"+dateTime.toString();
    m_mysql_db = QSqlDatabase::addDatabase("QMYSQL");
    //初始化 mysql 的私有变量
    //获取配置文件中的 数据库的配置信息

    QString db_name  = pPara->getValue("database_name");//"MySqlConfig",
    QString hostname = pPara->getValue("hostname");
    QString port = pPara->getValue("port");
    QString username = pPara->getValue("username");
    QString password = pPara->getValue("password");
    m_mysql_db.setDatabaseName(db_name);
    m_mysql_db.setHostName(hostname);
    m_mysql_db.setUserName(username);
    m_mysql_db.setPassword(password);
    m_mysql_db.setPort(port.toInt());

    //尝试打开该数据库文件
    bool ret = m_mysql_db.open();
    if ( !ret )
    {
        DEBUG_MYSQL("Error: Failed to connect mysql database\n");
    }
    else
    {
        DEBUG_MYSQL("Success: connect mysql database\n");
    }
}



bool  MySqlOper::executeSql(const QString &sql)
{
    QSqlQuery querySet(m_mysql_db);
    return querySet.exec(sql);
}
/**
* @brief: 获取员工信息
* @param：
* @return:
* @date: 2021-01-19
*/
Entity MySqlOper::getEmployerRecord(const QString &table_name, const QString &p_key, const QString &value)
{
    QSqlQuery querySet(m_mysql_db);
    Entity entity;
    QString sql = "select * from %1 where %2 = %3;";
    sql = sql.arg(table_name).arg(p_key).arg(value);
    DEBUG_MYSQL("sql %s",sql.toStdString().c_str());
    if( querySet.exec(sql))
    {
        if (querySet.first() )
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
