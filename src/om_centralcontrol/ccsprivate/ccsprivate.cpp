#include "ccsprivate.h"
#include "../om_common/utils/confighelperutil/confighelperutil.h"
#include "../om_common/datastruct/datastructs.h"
#include "../om_common/datastruct/databasesentity.h"
#include "../om_databases/mysql/mysqldaoimpl.h"

CCSPrivate::CCSPrivate()
{
    //获取配置文件
    ParameterData data = getMysqlConfigData();
    //初始化 mysql 配置类
    m_pDao = new MysqlDaoImpl(&data);
}

CCSPrivate::~CCSPrivate()
{
    if(nullptr != this->m_pDao)
    {
        delete m_pDao;
        m_pDao = nullptr;
    }
}

/**
* @brief: 初始化 mysql 数据访问 依赖配置文件解析工具 依赖配置文件信息
* @param：
* @return:
* @date: 2021-02-08
*/
ParameterData CCSPrivate::getMysqlConfigData()
{
    ConfigHelperUtil* pCfgUtil = ConfigHelperUtil::getInstance();
    QString db_name  = pCfgUtil->getValue("MySqlConfig","database_name");//"MySqlConfig",
    QString hostname = pCfgUtil->getValue("MySqlConfig","hostname");
    QString port = pCfgUtil->getValue("MySqlConfig","port");
    QString username = pCfgUtil->getValue("MySqlConfig","username");
    QString password = pCfgUtil->getValue("MySqlConfig","password");

    ParameterData configData;
    configData.appendItem("database_name",db_name);
    configData.appendItem("hostname",hostname);
    configData.appendItem("port",port);
    configData.appendItem("username",username);
    configData.appendItem("password",password);
    return configData;
}
/**
* @brief: 处理 登录信息服务
* @param： fromui  来自前端界面的  user 信息    一般是ParameterData 类型
*          fromDataBase 来自数据库的user 信息  一般是 Entity 类型
* @return: 返回两个信息是否一直
* @date: 2021-02-10
*/
ParameterData CCSPrivate::handleLoginService(const BaseStruct *fromUi)
{
    BaseStruct* pEntity = m_pDao->getData(fromUi,IDao::E_EMPLOYER_INFO);
    //强转 类型 改变内存的访问方式
    const Entity* fromDatabaseData = dynamic_cast<const Entity*>(pEntity);
    const ParameterData* fromUIData = dynamic_cast<const ParameterData*>(fromUi);
    if( nullptr!= fromUIData && nullptr != fromDatabaseData)
    {
        QString username1 = fromUIData->getValue("username");
        QString username2 = fromDatabaseData->at(MysqlDaoImpl::E_ID_INDEX).toString();
        ParameterData ret;
        if(username1 == username2)
        {
            QString password1 = fromUIData->getValue("password");
            QString password2 = fromDatabaseData->at(MysqlDaoImpl::E_PASS_INDEX).toString();
            if(password1 == password2)
            {
                ret.appendItem("is_vaild","true");
                ret.appendItem("profess",fromDatabaseData->at(MysqlDaoImpl::E_PROFESS_INDEX).toString());

                //回收 从数据库申请的内存
                delete pEntity;
                return ret;
            }
        }
        ret.appendItem("is_vaild","false");
        //回收 从数据库申请的内存
        delete pEntity;
        return ret;
    }
    //回收 从数据库申请的内存
    delete pEntity;
    return ParameterData();
}
/**
* @brief: 处理
* @param：
* @return:
* @date: 2021-02-15
*/
BaseStruct* CCSPrivate::handleModelRequest(const ParameterData &request)
{
    return m_pDao->getData(&request,IDao::E_FOOD_LIST_INFO);
}
