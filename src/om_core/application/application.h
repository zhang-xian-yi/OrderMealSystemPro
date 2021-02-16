#ifndef OM_CORE_APPLICATION_H
#define OM_CORE_APPLICATION_H
#include <QObject>
//界面
class IGui;
//系统托盘
class SystemTrayIcon;
//中央控制系统
class CentralControlSys;
//子系统 接口
class ISystem;
class ParameterData;

class OrderMealApplication:public QObject
{
    Q_OBJECT
public:
    static OrderMealApplication* getInstance();
    bool startApplication();
    bool stopApplication();



private slots:
    void slotAppExit();
    void slotResponseLogin(const ParameterData& data);
private:
    void initApplication();
    void initConnects();
private:
    void stopLoginUi();
private:
    // Forbid external construction
    OrderMealApplication();
    // External destructions are prohibited
    ~OrderMealApplication();
    // External replication constructs are prohibited
    OrderMealApplication(const OrderMealApplication &)=delete;
    // Prohibit external assignment operations
    OrderMealApplication &operator=(OrderMealApplication &)=delete;
private:
    //一般登录界面
    IGui*    m_ui;
    //Windows 系统托盘
    SystemTrayIcon* m_tray_icon;
    //中央控制系统
    CentralControlSys* m_control;
    //子系统
    ISystem*        m_childSystem;
};

#endif // OM_CORE_APPLICATION_H
