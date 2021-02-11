#include <QIcon>
#include "../om_common/utils/confighelperutil/confighelperutil.h"
#include "../om_ui/igui.h"
#include "../om_ui/loginui/logingui.h"
#include "../om_ui/systemtrayicon/systemtrayicon.h"
#include "../om_centralcontrol/centralcontrolsys.h"
#include "application.h"
/**
* @brief: 单例指针的获取方法
* @param：
* @return:
* @date: 2021-02-10
*/
OrderMealApplication *OrderMealApplication::getInstance()
{
    static OrderMealApplication instance;
    return &instance;
}
/**
* @brief: 构造函数
* @param：
* @return:
* @date: 2021-02-10
*/
OrderMealApplication::OrderMealApplication()
{
    m_ui = new LoginGUI;
    QStringList strList;
    strList << "点餐系统登陆" << "Login v1.0";
    QIcon icon(":/appfile/images/login/trayicon.ico");
    m_tray_icon = new SystemTrayIcon(strList,icon);
    m_control = CentralControlSys::getInstance();
    //读取配置文件初始化 程序应用配置
    initApplication();
}
/**
* @brief: 析构函数
* @param：
* @return:
* @date: 2021-02-10
*/
OrderMealApplication::~OrderMealApplication()
{
    stopApplication();
}

/**
* @brief: 初始化 app
* @param：
* @return:
* @date: 2021-02-08
*/
void OrderMealApplication::initApplication()
{
    initConnects();
}
/**
* @brief: 启动application
* @param：
* @return:
* @date: 2021-02-10
*/
bool OrderMealApplication::startApplication()
{
    //登录窗口
    m_ui->startGui();
    return true;
}
/**
* @brief: 停滞app 的运行
* @param：
* @return:
* @date: 2021-02-10
*/
bool OrderMealApplication::stopApplication()
{
    //释放自己所占据的资源
    if(nullptr != m_ui)
    {
        m_ui->stopGui();
        delete m_ui;
        m_ui = nullptr;
    }
    if(nullptr != m_tray_icon)
    {
        delete m_tray_icon;
        m_tray_icon = nullptr;
    }
    return true;
}
/**
* @brief: 停滞app 的运行
* @param：
* @return:
* @date: 2021-02-10
*/
void OrderMealApplication::slotAppExit()
{
    stopApplication();
    exit(3);
}

/**
* @brief: 初始化 函数的信号与槽的连接关系
* @param：
* @return:
* @date: 2021-02-09
*/
void OrderMealApplication::initConnects()
{
    connect(static_cast<LoginGUI*>(m_ui),&LoginGUI::signalLogin,m_control,&CentralControlSys::slotLogin);
    connect(static_cast<LoginGUI*>(m_ui),&LoginGUI::signalAppExit,this,&OrderMealApplication::slotAppExit);
    //系统托盘图标 和登录界面的connect
    connect(m_tray_icon,SIGNAL(signalStopApp()),this,SLOT(slotAppExit() ) );
}



