#include "ordermealapp.h"

#include <QTime>
#include <QMovie>
#include <QThread>
#include <QMessageBox>
#include "confighelperutil.h"
#include "publicenum.h"

OrderMealApp::OrderMealApp()
{
   initApp();
}

OrderMealApp::~OrderMealApp()
{
    stopApp();
    QThread::currentThread()->exit();
}

bool  OrderMealApp::initApp()
{
    bool ret = false;
    m_login = new LoginUi();
    m_control = new SysServiceControl();
    QStringList strList;
    strList << "点餐系统登陆" << "Login v1.0";
    QIcon icon(":/appfile/images/login/trayicon.ico");
    m_tray_icon = new SystemTrayIcon(strList,icon,nullptr);

    ret = initConnect();

    return ret;
}

void OrderMealApp::slot_recv_login_info(const int cmd)
{
    if(PublicType::LOGIN_SUCC == cmd)
    {
        m_tray_icon->setParentWidget(nullptr);
        delete m_login;
        m_login = nullptr;
    }
    else if(PublicType::LOGIN_FAILED == cmd)
    {
        QMessageBox::warning(m_login,"登录信息警告","密码或者名字/工号错误");
    }
}

bool OrderMealApp::initConnect()
{
    connect(m_tray_icon, SIGNAL(signal_showWin()), m_login, SLOT(slot_trayIcon()));
    connect(m_login,SIGNAL(signalLogin( const QString ,const QString )),m_control,SLOT(slot_dealLogin( const QString ,const QString )));
    connect(m_control,SIGNAL(signal_login_info(const int )),this,SLOT(slot_recv_login_info(const int )));
    //链接 停止/app 的程序
    connect(m_login,SIGNAL(signal_stopApp(const int&)),this,SLOT(slot_stopApp(const int& )));
    connect(m_control,SIGNAL(signal_stopApp(const int& )) ,this,SLOT(slot_stopApp(const int&)));
    connect(m_tray_icon,SIGNAL(signal_stopApp(const int&)),this,SLOT(slot_stopApp(const int& )));
    return true;
}




void OrderMealApp::startApp()
{
    //程序启动的动画


    //gif_src.set
    m_login->show();

    //程序启动完成之后
    m_run = true;
}

void OrderMealApp::slot_stopApp(const int& type)
{
    switch (type)
    {
        case PublicType::NORMAL_EXIT_APP:
        {
            stopApp();
            break;
        }
        case PublicType::LOAD_UI_ERROR:
        {
            stopApp();
            break;
        }
    }


}

bool OrderMealApp::stopApp()
{
    m_run = false;
    if(nullptr != m_control)
    {
        delete m_control;
        m_control = nullptr;
    }
    if(nullptr != m_tray_icon)
    {
        delete m_tray_icon;
        m_tray_icon = nullptr;
    }
    if(nullptr != m_login)
    {
        delete m_login;
        m_login = nullptr;
    }
    return true;
}
