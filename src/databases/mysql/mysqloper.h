#ifndef MYSQLOPER_H
#define MYSQLOPER_H


#include <QSqlDatabase>
#include "entity.h"
#include "publicenum.h"

class MySqlOper
{
public:
    static MySqlOper* getInstance()
    {
        static MySqlOper instance;
        return &instance;
    }
    /*获取 一条记录*/
    Entity getRecord(const QString& table_name,const QString& p_key,const QString& value,const int& flag);
    /*获取 food 的list 并返回实体*/
    QList<Entity> getFoodListByType(const QString& type);
private:
    /*初始化配置文件*/
    static void initConfig();
    /*获取 员工的个人记录*/
    Entity getEmployerRecord(const QString &table_name, const QString &p_key, const QString &value);
    /*执行sql 语句*/
    bool executeSql(const QString& sql);
private:
    // Forbid external construction
    MySqlOper();
    // External destructions are prohibited
    ~MySqlOper();
    // External replication constructs are prohibited
    MySqlOper(const MySqlOper &)=delete;
    // Prohibit external assignment operations
    MySqlOper &operator=(MySqlOper &)=delete;
private:
    static QSqlDatabase m_mysql_db;
};

#endif // MYSQLOPER_H
