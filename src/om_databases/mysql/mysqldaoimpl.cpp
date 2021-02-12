#include "mysqldaoimpl.h"

#include "mysql/mysqloper.h"

#include "../om_common/commoninc/commoninterface.h"
#include "../om_common/datastruct/datastructs.h"
#include "../om_common/datastruct/databasesentity.h"

/**
* @brief: 设置配置文件信息
* @param：
* @return:
* @date: 2021-01-18
*/
MysqlDaoImpl::MysqlDaoImpl()
{
    m_mysqlDao = nullptr;
}

MysqlDaoImpl::MysqlDaoImpl(const BaseStruct *para)
{
    m_mysqlDao = nullptr;
    setConfigData(para);
}

MysqlDaoImpl::~MysqlDaoImpl()
{
    if(nullptr != m_mysqlDao)
    {
        delete m_mysqlDao;
        m_mysqlDao = nullptr;
    }
}

BaseStruct *MysqlDaoImpl::getData(const BaseStruct *iPara, int flag)
{
    if(IDao::E_EMPLOYER_INFO == flag)
    {
        Entity* pEntity = new Entity;
        const ParameterData* pCfgData = dynamic_cast<const ParameterData*>(iPara);
        //需要查询的信息
        QString key_name = "id";
        QString value = pCfgData->getValue("username");
        *pEntity = m_mysqlDao->getEmployerRecord(key_name,value);
        return pEntity;

    }
    else if(IDao::E_FOOD_LIST_INFO == flag)
    {
        //补充食物列表的返回值数据
        EntityList* pEntityList = new EntityList;
        const ParameterData* pCfgData = dynamic_cast<const ParameterData*>(iPara);
        QString type = pCfgData->getValue("type");
        pEntityList->setEntityList(m_mysqlDao->getFoodListByType(type));
        return pEntityList;
    }
    return nullptr;
}

bool MysqlDaoImpl::setConfigData(const BaseStruct *para)
{
    const ParameterData* pData = dynamic_cast<const ParameterData*>(para);
    if(nullptr != pData)
    {
        m_mysqlDao = new MySqlOper(pData);
        return true;
    }
    return false;
}
