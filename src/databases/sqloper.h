#ifndef SQLOPER_H
#define SQLOPER_H
#include <QSqlDatabase>
//声明创建数据库 或者表的数据结构
#include "sqlglobal.h"



class SQLoper
{
public:
    SQLoper();
    bool createTable(SQLiteTable& table);

    bool insertRecord(QString table_name,QVector<QString> values);
    bool deketeRecord(QString table_name, QString p_key,QString uuid);
private:
    bool execSQL(const QString& sql);
private:
    QSqlDatabase m_sqlite_db;
};

#endif // SQLOPER_H
