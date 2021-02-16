//本模块内部业务类
#include "ccsprivate/ccsprivate.h"
#include "centralcontrolsys.h"
#include "../om_common/datastruct/databasesentity.h"
#include "../om_databases/idao.h"



CentralControlSys::CentralControlSys()
{
    m_servicePrivate = new CCSPrivate;
}

CentralControlSys::~CentralControlSys()
{
    if(nullptr != this->m_servicePrivate)
    {
        delete m_servicePrivate;
        m_servicePrivate = nullptr;
    }
}
/**
* @brief: 单例模式的 外部接口函数
* @param：void
* @return: 本对象的唯一指针
* @date: 2021-02-08
*/
CentralControlSys *CentralControlSys::getInstance()
{
    static CentralControlSys instance;
    return &instance;
}

/**
* @brief: 登录信息的响应函数  通过用户校验后，成功登录的信号发送给app  失败信号发送给前端登录界面
* @param：
* @return:
* @date: 2021-02-08
*/
void CentralControlSys::slotLogin(const ParameterData &fromUI)
{
    ParameterData ret = m_servicePrivate->handleLoginService(&fromUI);
    if( "true" == ret.getValue("is_vaild")  )
    {
        emit signalResponseLoginSucc(ret);
    }
    else
    {
        //登录失败
        ret.appendItem("msg",QStringLiteral("登陆失败,密码或者账号错误"));
        emit signalResponseLoginFailed(ret);
    }
}
/**
* @brief: 从数据库 中获取 food 清单数据
* @param：frommodel 一般为 type:"meat"  方式 其中 值由配置文件决定
* @return: void
* @date: 2021-02-15
*/
void CentralControlSys::slotGetFoodDataByTypeFromDatabase(const ParameterData &fromModel)
{
    BaseStruct* pBase = m_servicePrivate->handleModelRequest(fromModel);
    EntityList* pList = dynamic_cast<EntityList*>(pBase);
    QString type = fromModel.getValue("type");
    emit signalResponseModelRequest(type,*pList);
}

