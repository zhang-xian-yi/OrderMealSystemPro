#include "systemtrayicon.h"
#include <QApplication>
#include <QThread>
#pragma execution_character_set("utf-8")

SystemTrayIcon::SystemTrayIcon(QStringList strList, QIcon icon,QWidget* parent)
    : QWidget(parent)
{
    pWidget = parent;
    m_strList = strList;
    m_icon = icon;
    createAct();
    createTrayMenu();
    createTrayIcon();
}

bool SystemTrayIcon::closeTrayIcon()
{
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

    if(nullptr != m_trayIcon )
    {
        delete m_trayIcon;
        m_trayIcon = nullptr;
    }
    if(nullptr != menu )
    {
        delete menu;
        menu = nullptr;
    }
    return true;
}

SystemTrayIcon::~SystemTrayIcon()
{
    closeTrayIcon();
    QThread::currentThread()->exit();
}

bool SystemTrayIcon::setParentWidget(QWidget *parent)
{
    pWidget = parent;
    createAct();
    createTrayMenu();
    createTrayIcon();
    return true;
}

void SystemTrayIcon::createAct()
{
    if(nullptr == actMin)
    {
        actMin = new QAction("等待更新(&N)",this);
    }
    //connect(actMin,SIGNAL(triggered()),pWidget,SLOT(hide()));

    if(nullptr == actNormal)
    {
        actNormal = new QAction("等待更新(&R)",this);
    }
    //connect(actNormal,SIGNAL(triggered()),pWidget,SLOT(showNormal()));

    if(nullptr == actExit)
    {
        actExit = new QAction("退出(&Q)",this);
    }
    connect(actExit,SIGNAL(triggered()),this,SLOT(slot_app_exit()));
}

void SystemTrayIcon::createTrayMenu()
{
    if(nullptr == menu)
    {
        menu = new QMenu((QWidget*)QApplication::desktop());
        menu->addAction(actMin);
        menu->addAction(actNormal);
        menu->addSeparator();     //加入一个分离符
        menu->addAction(actExit);
    }
}

void SystemTrayIcon::createTrayIcon()
{
    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        return;
    }

    if(nullptr == m_trayIcon)
    {
        m_trayIcon = new QSystemTrayIcon(pWidget);
        m_trayIcon->setIcon(m_icon);   //设置图标图片
        m_trayIcon->setToolTip(m_strList.at(1));    //托盘时，鼠标放上去的提示信息
        m_trayIcon->showMessage(m_strList.at(0), m_strList.at(1), QSystemTrayIcon::Information, 10000);
        m_trayIcon->setContextMenu(menu);     //设置托盘上下文菜单
    }
    //如果存在图标 直接使用
    m_trayIcon->show();
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(slot_iconActivated(QSystemTrayIcon::ActivationReason)));
}


void SystemTrayIcon::slot_app_exit()
{
    closeTrayIcon();
    emit signalStopApp();
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
        if( nullptr != pWidget )
        {
            pWidget->setWindowState(Qt::WindowActive);
            emit signal_showWin();
            pWidget->show();
        }
        break;
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        break;
    }
}
