#ifndef ORDERMEALAPP_H
#define ORDERMEALAPP_H

#include <QObject>
#include <QLibrary>
#include <QApplication>
#include "loginui.h"
#include "systemtrayicon.h"
#include "sysservicecontrol.h"


class OrderMealApp:public QObject
{
    Q_OBJECT

public:
    explicit OrderMealApp();
    ~OrderMealApp();
public slots:
    void startApp();
    void slot_stopApp(const int& type);
    //response the SysServiceControl signal slot
    void slot_recv_login_info(const int cmd);
public:

private:
    bool initApp();
    bool initConnect();
    bool stopApp();
private:
     LoginUi* m_login = nullptr;
     SystemTrayIcon* m_tray_icon = nullptr;
     SysServiceControl* m_control = nullptr;
     bool m_run = false;
};

#endif // ORDERMEALAPP_H
