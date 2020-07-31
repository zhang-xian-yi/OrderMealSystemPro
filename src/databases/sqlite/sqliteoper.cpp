#include "sqliteoper.h"
#include <QSqlError>
#include <QSqlQuery>
#include "confighelperutil.h"
#include "global.h"
#include <QFile>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

SQLiteOper::SQLiteOper()
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
    QString db_name  = ConfigHelperUtil::getInstance().getValue("SQLiteConfig","database_name");
    QString hostname = ConfigHelperUtil::getInstance().getValue("SQLiteConfig","hostname");
    //QString port = ConfigHelperUtil::getInstance().getValue("SQLiteConfig","hostname");
    QString username = ConfigHelperUtil::getInstance().getValue("SQLiteConfig","username");
    QString password = ConfigHelperUtil::getInstance().getValue("SQLiteConfig","password");
    m_sqlite_db.setDatabaseName(db_name);
    m_sqlite_db.setHostName(hostname);
    m_sqlite_db.setUserName(username);
    m_sqlite_db.setPassword(password);
    //尝试打开该数据库文件
    if ( ! m_sqlite_db.open() )
    {
        TRACE("Error: Failed to connect database. %s\n",m_sqlite_db.lastError().text().toLatin1().toStdString().c_str());
    }
}


bool SQLiteOper::createTable(SQLiteTable & table)
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
    TRACE("createTable fun sql = %s\n",sql.toStdString().c_str());

    return execSQL(sql);
}

bool SQLiteOper::execSQL(const QString& sql)
{
    //创建表格
    static QSqlQuery sql_query;
    if(! sql_query.exec(sql))
    {
        TRACE("Error: Fail to exec sql .%s \n",sql_query.lastError().text().toStdString().c_str());
        return false;
    }
    else
    {
        TRACE("sql exec succ!\n");
        return true;
    }
}

bool SQLiteOper::insertRecord(QString table_name, QVector<QString> values)
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
    TRACE("insertRecord fun :sql = %s\n",sql.toStdString().c_str());
    return execSQL(sql);
}

bool SQLiteOper::deketeRecord(QString table_name, QString p_key,QString uuid)
{
    //delete from student where id = 1
    QString sql = "delete from "+table_name+" where "+p_key;
    //id  删除  不能符合所有的删除操作 也许可传入参数 表征传入的字段名
    sql += "= '"+uuid+"'"+";";
    TRACE("deleteRecord fun :sql = %s\n",sql.toStdString().c_str());
    return execSQL(sql);
}
