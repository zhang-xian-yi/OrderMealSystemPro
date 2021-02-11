#ifndef OM_DATABASE_MYSQLDAOIMPL_H
#define OM_DATABASE_MYSQLDAOIMPL_H

#include "../idao.h"

#include <QtCore/qglobal.h>
#if defined(OM_DATABASES_LIBRARY)
#  define OM_DATABASES_EXPORT Q_DECL_EXPORT
#else
#  define OM_DATABASES_EXPORT Q_DECL_IMPORT
#endif

class MySqlOper;
class BaseStruct;

class OM_DATABASES_EXPORT MysqlDaoImpl:public IDao
{
public:
    enum EntityIndex
    {
        E_ID_INDEX = 0,
        E_PROFESS_INDEX,
        E_NAME_INDEX,
        E_PASS_INDEX
    };
    explicit MysqlDaoImpl();
    //一般是 parameterData 结构 也就是键值对
    explicit MysqlDaoImpl(const BaseStruct* para);
    ~MysqlDaoImpl();
    //设置配置文件信息
    bool setConfigData(const BaseStruct* para);
    //参数也许可以修改
    virtual BaseStruct* getData(const BaseStruct* iPara,int flag);
private:
    MySqlOper* m_mysqlDao;
};

#endif // OM_DATABASE_MYSQLDAOIMPL_H
