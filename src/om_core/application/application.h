#ifndef OM_CORE_APPLICATION_H
#define OM_CORE_APPLICATION_H
#include <QObject>
//界面
class IGui;
//系统托盘
class SystemTrayIcon;
//中央控制系统
class CentralControlSys;
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
    // Forbid external construction
    OrderMealApplication();
    // External destructions are prohibited
    ~OrderMealApplication();
    // External replication constructs are prohibited
    OrderMealApplication(const OrderMealApplication &)=delete;
    // Prohibit external assignment operations
    OrderMealApplication &operator=(OrderMealApplication &)=delete;
private:
    IGui*    m_ui;
    SystemTrayIcon* m_tray_icon;
    CentralControlSys* m_control;
};

#endif // OM_CORE_APPLICATION_H
