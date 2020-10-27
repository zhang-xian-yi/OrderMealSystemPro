#ifndef SQLSERVICE_H
#define SQLSERVICE_H
#include "sqliteoper.h"
#include "mysqloper.h"
#include "entity.h"

class SQLService
{
public:
    SQLService();
    ~SQLService();

    bool checkEmployerInfo(const QString& uuid,const QString& password,int* out_profess);
private:
    SQLiteOper* m_sqlite_dao;
    MySqlOper* m_mysql_dao;
};

#endif // SQLSERVICE_H
