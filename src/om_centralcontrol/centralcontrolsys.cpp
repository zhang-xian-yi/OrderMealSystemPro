﻿//本模块内部业务类
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
* @brief: 登录信息的响应函数
* @param：
* @return:
* @date: 2021-02-08
*/
void CentralControlSys::slotLogin(const ParameterData &fromUI)
{
    ParameterData ret = m_servicePrivate->handleLoginService(&fromUI);
    if(ret.getValue("msg") == "true")
    {
        //登录成功
        emit signalResponseLogin(ret);
    }
    else
    {
        //登录失败
        ret.appendItem("msg",QStringLiteral("登陆失败,密码或者账号错误"));
        emit signalResponseLogin(ret);
    }
}

