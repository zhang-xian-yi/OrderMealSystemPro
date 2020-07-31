#ifndef SQLGLOBAL_H
#define SQLGLOBAL_H

#include <QVector>
#include <QString>

class SQLiteTable
{
public:
    QString table_name;
    QVector<QString> key;
    QVector<QString> key_type;
public:
    SQLiteTable(QString table_name,QVector<QString> key,QVector<QString> key_type)
    {
        this->table_name = table_name;
        this->key = key;
        this->key_type = key_type;
    }
};


class SQLiteRecord
{
public:
    QString table_name;
    QVector<QString> values;
public:
    SQLiteRecord(QString table_name,QVector<QString> values)
    {
        this->table_name = table_name;
        this->values = values;
    }
};

#include <QTextCodec>
#include <QString>

#define FromQString(x) QTextCodec::codecForLocale()->fromUnicode(x).toStdString()
#define ToQString(x) QTextCodec::codecForLocale()->toUnicode((x).c_str())

#endif // SQLGLOBAL_H
