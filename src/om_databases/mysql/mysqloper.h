#ifndef MYSQLOPER_H
#define MYSQLOPER_H
#include <QSqlDatabase>
#include "../om_common/datastruct/databasesentity.h"

class BaseStruct;
class ParameterData;

class MySqlOper
{
public:
    explicit MySqlOper(const BaseStruct* pPara);
    ~MySqlOper();
    /*获取 员工的个人记录*/
    Entity getEmployerRecord(const QString &p_key, const QString &value);
    /*获取 food 的list 并返回实体*/
    QList<Entity> getFoodListByType(const QString& type);
private:
    Entity getRecord(const QString &table_name, const QString &p_key, const QString &value);
    /*初始化配置文件*/
    void initConfig(const ParameterData* pPara);

    /*执行sql 语句*/
    bool executeSql(const QString& sql);
private:
    QSqlDatabase m_mysql_db;
    QString m_connect_name;
};

#endif // MYSQLOPER_H
