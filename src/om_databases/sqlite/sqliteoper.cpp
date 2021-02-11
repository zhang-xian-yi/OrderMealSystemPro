#include "sqliteoper.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include "../om_common/utils/confighelperutil/confighelperutil.h"
#include "../om_common/commoninc/debugdefine.h"


//明明空间 枚举一些index
namespace DataBasesSpace {
enum EmployerIndex{
        id_index = 0,
        profess_index,
        name_index,
        password_index
};

enum FoodIndex{
    Name_index = 0,
    Price_index,
    Desc_index,
    ImgUrl_index,
    Type_index
};

}

void SQLiteOper::initSQLCOnfig()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        m_sqlite_db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        //初始化 sqlite 的私有变量
        m_sqlite_db = QSqlDatabase::addDatabase("QSQLITE");
    }


    //获取配置文件中的 关于sqlite数据库 的数据库名 为数据库文件的名字
    QString db_name  = ConfigHelperUtil::getInstance()->getValue("SQLiteConfig","database_name");
    QString hostname = ConfigHelperUtil::getInstance()->getValue("SQLiteConfig","hostname");
    //QString port = ConfigHelperUtil::getInstance().getValue("SQLiteConfig","hostname");
    QString username = ConfigHelperUtil::getInstance()->getValue("SQLiteConfig","username");
    QString password = ConfigHelperUtil::getInstance()->getValue("SQLiteConfig","password");
    m_sqlite_db.setDatabaseName(db_name);
    m_sqlite_db.setHostName(hostname);
    m_sqlite_db.setUserName(username);
    m_sqlite_db.setPassword(password);
    //尝试打开该数据库文件
    if ( ! m_sqlite_db.open() )
    {
        DEBUG_SQLITE("Error: Failed to connect database. %s\n",m_sqlite_db.lastError().text().toLatin1().toStdString().c_str());
    }
}


SQLiteOper::SQLiteOper()
{
    initSQLCOnfig();
}

bool SQLiteOper::createTable(const SQLiteTable & table)
{
    //QString sql = "create table student(id int primary key, name text, age int)";
    //构建创建表格的字符串
    QString sql = "create table ";
    sql += table.table_name;
    //构建左括号
    sql += "(";
    //构建第一个字段后面自动跟 ‘,’
    sql += table.key.at(0);
    sql += " " + table.key_type.at(0);
    //从第二个字段开始防止 ‘ 多出一个
    for(int i = 1;i<table.key.size();++i)
    {
        sql += ",";
        sql += table.key.at(i);
        sql += " " + table.key_type.at(i);
    }
    sql += ");";
    DEBUG_SQLITE("createTable fun sql = %s\n",sql.toStdString().c_str());

    return executeSQL(sql);
}

bool SQLiteOper::executeSQL(const QString& sql)
{
    //创建表格
    static QSqlQuery sql_query;
    if(! sql_query.exec(sql))
    {
        DEBUG_SQLITE("Error: Fail to exec sql .%s \n",sql_query.lastError().text().toStdString().c_str());
        return false;
    }
    else
    {
        DEBUG_SQLITE("sql exec succ!\n");
        return true;
    }
}

Entity SQLiteOper::executeSQL(const QString& sql,const int& record_col_length)
{
    QSqlQuery querySet;
    querySet.exec(sql);
    QVariantList record;
    while(querySet.next())
    {
        for(int i = 0;i<record_col_length;++i)
        {
            record<<querySet.value(i);
        }
    }
    return Entity(record);
}

bool SQLiteOper::executeSQL(const QString &sql, QList<Entity> &data)
{
    QSqlQuery querySet;
    querySet.exec(sql);

    while(querySet.next())
    {
        Entity record(QVariantList() << querySet.value(DataBasesSpace::Name_index)
                                    << querySet.value(DataBasesSpace::Price_index)
                                    << querySet.value(DataBasesSpace::Desc_index)
                                    << querySet.value(DataBasesSpace::ImgUrl_index)
                                    << querySet.value(DataBasesSpace::Type_index));
        data.push_back(record);
    }
    if(! data.empty())
    {
        //查询的数据不为空
        DEBUG_SQLITE("sqlite sql-查询数据成功\n");
        return true;
    }
    else
    {
        DEBUG_SQLITE("sqlite-sql-数据集合为空");
        return false;
    }
}

bool SQLiteOper::insertRecord(const QString& table_name, const QVector<QString>& values)
{
    //"INSERT INTO student VALUES(1, \"Wang\", 23)"
    QString sql = "insert into "+table_name+" values(";
    sql += "'"+values.at(0)+"'";
    //从1 开始
    for(int i = 1;i<values.size();++i)
    {
        sql += ",";
        sql += "'"+values.at(i)+"'";
    }
    sql += ");";
    DEBUG_SQLITE("insertRecord fun :sql = %s\n",sql.toStdString().c_str());
    return executeSQL(sql);
}

bool SQLiteOper::deketeRecord( const QString& table_name, const QString& p_key,const QString& uuid)
{
    //delete from student where id = 1
    QString sql = "delete from "+table_name+" where "+p_key;
    //id  删除  不能符合所有的删除操作 也许可传入参数 表征传入的字段名
    sql += "= '"+uuid+"'"+";";
    DEBUG_SQLITE("deleteRecord fun :sql = %s\n",sql.toStdString().c_str());
    return executeSQL(sql);
}

QList<Entity> SQLiteOper::getFoodRecoreds(const QString& p_key,const QString& value)
{
    static QList<Entity> dataList;
    //清空存储的数据
    dataList.clear();
    QString sql = "select name,price,describe,imgurl from db_food_menu where "+p_key;
    //id  删除  不能符合所有的删除操作 也许可传入参数 表征传入的字段名
    sql += "= '"+value+"'"+";";
    DEBUG_SQLITE("get records fun :sql = %s\n",sql.toStdString().c_str());
    executeSQL(sql,dataList);
    return dataList;
}

Entity SQLiteOper::getRecord(const QString& table_name,const QString& p_key,const QString& value)
{
    static Entity entity;
    QString sql = "select * from "+table_name+" where "+p_key;
    //通过某个可以唯一确定的id 来获取一个对象
    sql += "= '"+value+"'"+";";
    DEBUG_SQLITE("get records fun :sql = %s\n",sql.toStdString().c_str());
    return executeSQL(sql,5);
}
