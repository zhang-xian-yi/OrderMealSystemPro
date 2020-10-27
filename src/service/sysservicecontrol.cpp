#include "sysservicecontrol.h"
#include "global.h"

SysServiceControl::SysServiceControl(QObject* parent):
    QObject(parent),
    m_sql_service(new SQLService)
{
    init();
}

SysServiceControl::~SysServiceControl()
{
    if(nullptr != m_qml_view)
    {
        delete m_qml_view;
        m_qml_view = nullptr;
    }

    if(nullptr != m_sql_service)
    {
        delete  m_sql_service;
        m_sql_service = nullptr;
    }
}

bool SysServiceControl::init()
{
    bool ret = false;
    ret = initServicerQMLUI();
    return ret;
}

bool SysServiceControl::initServicerQMLUI()
{
    m_qml_view = new QQuickView();
    m_ctx = m_qml_view->rootContext();
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
        emit signal_login_info(LOGIN_SUCC);
        switch (profess)
        {
            default:break;
            case Sevicr:
            {
                //不在事件循环中 必须通过view 加载
                m_qml_view->setSource(QUrl("qrc:/src/ui/servicer/servicer.qml"));
                if(nullptr == m_qml_view->rootObject())
                {
                    emit signal_stopApp(LOAD_UI_ERROR);
                    DEBUG_SERVICE("load service qml error");
                    return;
                }
                m_qml_view->show();
                break;
            }
            case Cooker:
            {

                break;
            }
            case Counter:
            {

                break;
            }
            case Manager:
            {

                break;
            }
        }

    }
    else
    {
        //DEBUG_SERVICE("login failed");
        emit signal_login_info(LOGIN_FAILED);
    }
}
