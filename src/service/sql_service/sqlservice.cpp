#include "sqlservice.h"
#include "confighelperutil.h"
#include <QCryptographicHash>
#include "global.h"
#include "publicenum.h"


SQLService::SQLService():
    m_sqlite_dao(new SQLiteOper),
    m_mysql_dao(new MySqlOper)
{

}

SQLService::~SQLService()
{
    if(nullptr != m_sqlite_dao)
    {
        delete m_sqlite_dao;
    }
    if(nullptr != m_mysql_dao)
    {
        delete m_mysql_dao;
    }
}


bool SQLService::checkEmployerInfo(const QString &uuid, const QString &password,int* out_profess)
{
    QString table_name = ConfigHelperUtil::getInstance().getValue("MySqlConfig","table_user");
    QString table_primary = ConfigHelperUtil::getInstance().getValue("MySqlConfig","user_primary");
    //获取数据中存在的用户信息
    Entity sql_user = m_mysql_dao->getRecord(table_name,table_primary,uuid,PublicType::Employ_flag);
    //只要名字/工号匹配正确
    if(sql_user.at(EntityIndex::id_index) == uuid  || sql_user.at(EntityIndex::name_index) == uuid)
    {
        //进行密码检查
        //QByteArray bapass = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Md5);
        if(password == sql_user.at(EntityIndex::password_index))
        {
            *out_profess = sql_user.at(1).toInt();
            return true;
        }
        else
        {
            DEBUG_SERVICE("password error");
            return false;
        }
    }
    else
    {
        DEBUG_SERVICE("username not exist");
        return false;
    }
}


