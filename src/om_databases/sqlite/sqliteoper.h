#ifndef SQLITEOPER_H
#define SQLITEOPER_H

#include <QSqlDatabase>

//声明创建数据库 或者表的数据结构
#include "../om_common/datastruct/databasesentity.h"
#include "sqlitestruct.h"

#include <QtCore/qglobal.h>

#if defined(OM_DATABASES_LIBRARY)
#  define OM_DATABASES_EXPORT Q_DECL_EXPORT
#else
#  define OM_DATABASES_EXPORT Q_DECL_IMPORT
#endif

class OM_DATABASES_EXPORT SQLiteOper
{
public:
    SQLiteOper();
    bool createTable(const SQLiteTable& table);

    bool insertRecord(const QString& table_name,const QVector<QString>& values);
    bool deketeRecord(const QString& table_name, const QString& p_key,const QString& uuid);
    Entity getRecord(const QString& table_name,const QString& p_key,const QString& value);
    QList<Entity> getFoodRecoreds(const QString& p_key,const QString& value);
private:

    bool executeSQL(const QString& sql);
    bool executeSQL(const QString& sql,QList<Entity>& data);
    //执行一个sql 语句 返回改sql 语句查询的一条记录  需要传入顺序情况下的列数
    Entity executeSQL(const QString& sql,const int& record_col_length);
    void initSQLCOnfig();
private:
    QSqlDatabase m_sqlite_db;
};

#endif // SQLITEOPER_H
