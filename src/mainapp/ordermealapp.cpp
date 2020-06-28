#include "ordermealapp.h"

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
    m_login->show();


}
