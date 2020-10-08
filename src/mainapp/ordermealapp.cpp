#include "ordermealapp.h"

#include <QTime>
#include <QMovie>
#include <QMessageBox>
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

void OrderMealApp::recv_login_info(const QString& msg)
{
    if("success" == msg)
    {
        this->m_login->close();
        this->m_tray_icon->close();
    }
    else
    {
        QMessageBox::warning(nullptr,"登录信息警告",msg);
    }
}

void OrderMealApp::startApp()
{
    //程序启动的动画


    //gif_src.set
    m_login->show();

    //程序启动完成之后

}
