#include "ordermealapp.h"

#include <QPixmap>
#include <QSplashScreen>
#include <QTime>
OrderMealApp::OrderMealApp()
{
   initApp();

}

OrderMealApp::~OrderMealApp()
{
    if( nullptr !=  m_login )
    {
        delete m_login;
    }

    if(nullptr != m_tray_icon)
    {
        delete m_tray_icon;
    }
}

void OrderMealApp::initApp()
{
    m_login = new LoginUi();

    QStringList strList;
    strList << "点餐系统登陆" << "Login v1.0";
    QIcon icon(":/appfile/images/login/trayicon.ico");
    m_tray_icon = new SystemTrayIcon(strList,icon,m_login);
    connect(m_tray_icon, SIGNAL(signal_showWin()), m_login, SLOT(slot_trayIcon()));

}

void OrderMealApp::startApp()
{
    //程序启动的动画
    /*
    QPixmap pic(":/appfile/images/start/init.gif");
    QSplashScreen splash(pic);
    splash.show();
    for(int i = 0;i<800000000;++i);
    */
    m_login->show();
    //程序启动完成之后
    //splash.finish(m_login);
}
