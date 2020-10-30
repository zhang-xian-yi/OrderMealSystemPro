#ifndef QMLSERVICE_H
#define QMLSERVICE_H
#include <QObject>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include "qml_connect/qmlconnecter.h"
#include "qml_model/modelfactory.h"

class QMLService:public QObject
{
    Q_OBJECT
public:
    explicit QMLService();
    ~QMLService();

    /*初始化服务员界面的ui*/
    bool initServicerContext();
private:
    /*初始化必要的 成员变量*/
    bool initQMLUI();
    /*初始化 service qml 交互的 5 对象*/
    bool init5TypeData();
private:
    /*quick view 加载界面 ui 的view*/
    QQmlApplicationEngine * m_qml_engine = nullptr;
    /*链接对象*/
    QMLCmdConnecter* m_cmd_connect = nullptr;
    QList<QAbstractListModel*> m_model_list;
};

#endif // QMLSERVICE_H
