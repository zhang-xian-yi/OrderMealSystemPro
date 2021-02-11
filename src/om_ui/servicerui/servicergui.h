#ifndef OM_UI_SERVICERGUI_H
#define OM_UI_SERVICERGUI_H

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>

#include "igui.h"

class ServicerGui:public IGui
{
public:
    //通过构造函数传入需要的model 数据
    explicit ServicerGui();
    ~ServicerGui();
    virtual int startGui();
    virtual int stopGui();
private:
    /*quick view 加载界面 ui 的view*/
    QQmlApplicationEngine* m_qmlEngine = nullptr;
};

#endif // OM_UI_SERVICERGUI_H
