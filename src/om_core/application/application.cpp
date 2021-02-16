#include <QIcon>
#include <QMessageBox>
#include <QEventLoop>
#include <QTimer>
//common
#include "../om_common/utils/confighelperutil/confighelperutil.h"
#include "../om_common/datastruct/datastructs.h"
//ui
#include "../om_ui/igui.h"
#include "../om_ui/loginui/logingui.h"
#include "../om_ui/systemtrayicon/systemtrayicon.h"
//ccs
#include "../om_centralcontrol/centralcontrolsys.h"
//服务员子系统
#include "../om_childsystem/isystem.h"
#include "../om_childsystem/servicersystem/servicerchildsystem.h"
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
    m_childSystem = nullptr;
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
    if(nullptr != m_childSystem)
    {
        m_childSystem->stopSystem();
        delete  m_childSystem;
        m_childSystem = nullptr;
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
* @brief: 响应 控制系统的 登录反馈信息
* @param：  data 的key 存在 msg/is_vaild/profess   但is_vaild == true时 proefess 存在 只会接受succ 信号
* @return:
* @date: 2021-02-12
*/
void OrderMealApplication::slotResponseLogin(const ParameterData &data)
{
    stopLoginUi();
    QString professId = data.getValue("profess");
    //获取子系统profess 标志 并初始化子系统
    switch (professId.toInt())
    {
        case ISystem::E_SERVICER_SYSTEM:
        {
            m_childSystem = new ServicerChildSystem();
            connect(static_cast<ServicerChildSystem*>(m_childSystem),&ServicerChildSystem::signalGetFoodDataByType,
                    m_control,&CentralControlSys::slotGetFoodDataByTypeFromDatabase);
            connect(m_control,&CentralControlSys::signalResponseModelRequest,
                    static_cast<ServicerChildSystem*>(m_childSystem),&ServicerChildSystem::slotFromDatabaseFood);
            break;
        }
    }
    if(nullptr!=m_childSystem)
    {
        //初始化数据
        m_childSystem->initModelData();
        //启动子系统
        m_childSystem->startSystem();
    }
    else
    {
        //结束程序
        slotAppExit();
    }
}

/**
* @brief: 初始化 函数的信号与槽的连接关系
* @param：
* @return:
* @date: 2021-02-09
*/
void OrderMealApplication::initConnects()
{
    //前端界面的connect
    connect(static_cast<LoginGUI*>(m_ui),&LoginGUI::signalLogin,m_control,&CentralControlSys::slotLogin);
    connect(static_cast<LoginGUI*>(m_ui),&LoginGUI::signalAppExit,this,&OrderMealApplication::slotAppExit);
    connect(m_control,SIGNAL(signalResponseLoginFailed(const ParameterData&)),static_cast<LoginGUI*>(m_ui),SLOT(slotResponseLoginFailed(const ParameterData& )));
    //系统托盘图标 和登录界面的connect
    connect(m_tray_icon,SIGNAL(signalStopApp()),this,SLOT(slotAppExit() ) );
    //中央控制系统 和 application 的 connect
    connect(m_control,SIGNAL(signalResponseLoginSucc(const ParameterData&)),this,SLOT(slotResponseLogin(const ParameterData&)));
    //model 与 ccs 的connect
}
/**
* @brief: 停止 登陆界面的事件活动
* @param：
* @return:
* @date: 2021-02-16
*/
void OrderMealApplication::stopLoginUi()
{
    //取消登录 与 中央控制系统的 信号槽链接
    disconnect(static_cast<LoginGUI*>(m_ui),&LoginGUI::signalLogin,m_control,&CentralControlSys::slotLogin);
    disconnect(static_cast<LoginGUI*>(m_ui),&LoginGUI::signalAppExit,this,&OrderMealApplication::slotAppExit);
    disconnect(m_control,SIGNAL(signalResponseLoginFailed(const ParameterData&)),static_cast<LoginGUI*>(m_ui),SLOT(slotResponseLoginFailed(const ParameterData& )));
    //删除登录界面
    m_ui->stopGui();
    delete m_ui;
    m_ui = nullptr;
}



