#include "systemtrayicon.h"

#include <QApplication>
#include <QDebug>

#pragma execution_character_set("utf-8")

SystemTrayIcon::SystemTrayIcon(QStringList strList, QIcon icon, QWidget *parent)
    : QWidget(parent)
{
    pWidget = parent;
    m_strList = strList;
    m_icon = icon;
    createAct();
    createTrayMenu();
    createTrayIcon();
}

SystemTrayIcon::~SystemTrayIcon()
{
    if(nullptr != m_trayIcon )
    {
        delete m_trayIcon;
        m_trayIcon = nullptr;
    }
    if(nullptr != actMin )
    {
        delete actMin;
        actMin = nullptr;
    }
    if(nullptr != actNormal )
    {
        delete actNormal;
        actNormal = nullptr;
    }
    if(nullptr != actExit )
    {
        delete actExit;
        actExit = nullptr;
    }
    if(nullptr != menu )
    {
        delete menu;
        menu = nullptr;
    }
    if(nullptr != pWidget )
    {
        delete pWidget;
        pWidget = nullptr;
    }
}

void SystemTrayIcon::createAct()
{
    actMin = new QAction("最小化(&N)",this);
    connect(actMin,SIGNAL(triggered()),pWidget,SLOT(hide()));
    actNormal = new QAction("还 原(&R)",this);
    connect(actNormal,SIGNAL(triggered()),pWidget,SLOT(showNormal()));
    actExit = new QAction("退出(&Q)",this);
    connect(actExit,SIGNAL(triggered()),this,SLOT(slot_app_exit()));
}

void SystemTrayIcon::createTrayMenu()
{
    menu = new QMenu((QWidget*)QApplication::desktop());
    menu->addAction(actMin);
    menu->addAction(actNormal);
    menu->addSeparator();     //加入一个分离符
    menu->addAction(actExit);
}

void SystemTrayIcon::createTrayIcon()
{
    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        return;
    }

    m_trayIcon = new QSystemTrayIcon(pWidget);
    m_trayIcon->setIcon(m_icon);   //设置图标图片
    m_trayIcon->setToolTip(m_strList.at(1));    //托盘时，鼠标放上去的提示信息
    m_trayIcon->showMessage(m_strList.at(0), m_strList.at(1), QSystemTrayIcon::Information, 10000);
    m_trayIcon->setContextMenu(menu);     //设置托盘上下文菜单
    m_trayIcon->show();
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(slot_iconActivated(QSystemTrayIcon::ActivationReason)));
}

void SystemTrayIcon::slot_app_exit()
{
    //关闭系统托盘按钮
    this->close();
    //父控件释放的时候 会逐级释放子空间
    pWidget->close();
}

void SystemTrayIcon::slot_iconActivated(QSystemTrayIcon::ActivationReason reason)
{    
    switch (reason)
    {
    case QSystemTrayIcon::Unknown:
        break;
    case QSystemTrayIcon::Context:
        break;
    case QSystemTrayIcon::DoubleClick:
        pWidget->setWindowState(Qt::WindowActive);
        emit signal_showWin();
        pWidget->show();
        break;
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        break;
    }
}
