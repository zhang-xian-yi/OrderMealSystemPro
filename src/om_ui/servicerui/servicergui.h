#ifndef OM_UI_SERVICERGUI_H
#define OM_UI_SERVICERGUI_H

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QAbstractListModel>

#include "../igui.h"
#include <QtCore/qglobal.h>
#if defined(OM_UI_LIBRARY)
#  define OM_UI_EXPORT Q_DECL_EXPORT
#else
#  define OM_UI_EXPORT Q_DECL_IMPORT
#endif

class OM_UI_EXPORT ServicerGui:public IGui
{
public:
    //通过构造函数传入需要的model 数据
    explicit ServicerGui();
    ~ServicerGui();
    virtual int startGui();
    virtual int stopGui();
    void setModelData(const QList<QAbstractListModel*>& modelList);
private:
};

#endif // OM_UI_SERVICERGUI_H
