#ifndef ORDERMEALAPP_H
#define ORDERMEALAPP_H

#include <QObject>


#include "loginui.h"
#include "systemtrayicon.h"


class OrderMealApp:public QObject
{
    Q_OBJECT

public:
    OrderMealApp();
    ~OrderMealApp();
    void startApp();
public:
    //response the SysServiceControl signal slot
    void recv_login_info(const QString& msg);
private:
    void initApp();

private:
     LoginUi* m_login;
     SystemTrayIcon* m_tray_icon;
};

#endif // ORDERMEALAPP_H
