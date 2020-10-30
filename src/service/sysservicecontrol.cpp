#include "sysservicecontrol.h"
#include "global.h"


SysServiceControl::SysServiceControl(QObject* parent):
    QObject(parent),
    m_sql_service(new SQLService),
    m_qml_service(new QMLService)
{
    init();
}

SysServiceControl::~SysServiceControl()
{
    this->closeService();
}

bool SysServiceControl::init()
{
    bool ret = false;

    return ret;
}
/**
* @brief:  关闭服务 并释放所有资源（析构时调用）
* @param：
* @return:
* @date: 2020-10-29
*/
bool SysServiceControl::closeService()
{
    if(nullptr != m_qml_service)
    {
        delete m_qml_service;
        m_qml_service = nullptr;
    }
    if(nullptr != m_sql_service)
    {
        delete  m_sql_service;
        m_sql_service = nullptr;
    }
    return true;
}

/*
 input username ,password :const QString
 desc: 对用户名/工号 等唯一标记 进行数据库的查询 对从数据库返回的数据进行比较 存在则比较密码 ，不存在则返回信息
 比较密码正确 则发送登录成功的信号
 查询该工号所对应的员工类型
 */
void SysServiceControl::slot_dealLogin(const QString name,const QString passwd)
{
    int profess = -1;
    if(m_sql_service->checkEmployerInfo(name,passwd,&profess))
    {
        emit signal_login_info(PublicType::LOGIN_SUCC);
        switch (profess)
        {
            default:break;
            case PublicType::Sevicr:
            {
                /*使用 servicer 的上下文 并展示*/
                if (! m_qml_service->initServicerContext())
                {
                    emit signal_stopApp(PublicType::LOAD_UI_ERROR);
                    DEBUG_SERVICE("load servicer qml ui error");
                }
                break;
            }
            case PublicType::Cooker:
            {

                break;
            }
            case PublicType::Counter:
            {

                break;
            }
            case PublicType::Manager:
            {

                break;
            }
        }

    }
    else
    {
        //DEBUG_SERVICE("login failed");
        emit signal_login_info(PublicType::LOGIN_FAILED);
    }
}
