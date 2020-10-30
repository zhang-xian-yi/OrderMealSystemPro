#ifndef MYSQLOPER_H
#define MYSQLOPER_H


#include <QSqlDatabase>
#include "entity.h"
#include "publicenum.h"

class MySqlOper
{
public:
    MySqlOper();
    ~MySqlOper();
    Entity getRecord(const QString& table_name,const QString& p_key,const QString& value,const int& flag);

private:
    void initConfig();
    Entity getEmployerRecord(const QString &table_name, const QString &p_key, const QString &value);
    bool executeSql(const QString& sql);

private:
    QSqlDatabase m_mysql_db;
};

#endif // MYSQLOPER_H
