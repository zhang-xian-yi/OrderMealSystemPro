#ifndef SQLITEOPER_H
#define SQLITEOPER_H

#include <QSqlDatabase>

//声明创建数据库 或者表的数据结构
#include "sqlglobal.h"
#include "sqloper.h"

class SQLiteOper:public SQLoper
{
public:
    SQLiteOper();

private:
    bool execSQL(const QString& sql);
};

#endif // SQLITEOPER_H
