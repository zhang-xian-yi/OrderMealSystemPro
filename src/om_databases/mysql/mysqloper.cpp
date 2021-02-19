#include "mysqloper.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
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


/**
* @brief: 执行该sql 语句
* @param：
* @return:
* @date: 2021-02-12
*/
bool MySqlOper::executeSql(const QString &sql)
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
Entity MySqlOper::getEmployerRecord(const QString &p_key, const QString &value)
{
    return getRecord("tb_employer",p_key,value);;
}
/**
* @brief: 获取 指定表中的指定键值 的一条记录  泛型--编程 通用的查询记录
* @param：
* @return:
* @date: 2021-02-12
*/
Entity MySqlOper::getRecord(const QString &table_name, const QString &p_key, const QString &value)
{
    QString sql = "select * from %1 where %2 = %3;";
    sql = sql.arg(table_name).arg(p_key).arg(value);
    //构建 query 方法
    QSqlQuery querySet(sql,m_mysql_db);
    Entity entity;
    DEBUG_MYSQL("sql %s",sql.toStdString().c_str());
    if( querySet.next())
    {
        QSqlRecord rec = querySet.record();
        if(! rec.isEmpty())
        {
            QStringList list;
            //获取记录 字段的数目
            for (int index = 0; index < rec.count(); ++index)
            {
                if(! rec.value(index).isNull())
                {
                    list<<rec.value(index).toString();
                }
            }
            entity.setData(list);
        }
    }
    else
    {
        DEBUG_MYSQL("exec error %s",querySet.lastError().text().toStdString().c_str());
    }
    return entity;
}
/**
* @brief: 获取 食物具体信息列表
* @param：
* @return:
* @date: 2021-02-12
*/
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
