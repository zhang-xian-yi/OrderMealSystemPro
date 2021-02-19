#ifndef OM_CHILDSYSTEM_SERVICERCHILDSYSTEM_H
#define OM_CHILDSYSTEM_SERVICERCHILDSYSTEM_H
#include <QAbstractListModel>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include "../isystem.h"

#include <QtCore/qglobal.h>
#if defined(OM_CHILDSYSTEM_LIBARAY)
#  define OM_CHILDSYSTEM_EXPORT Q_DECL_EXPORT
#else
#  define OM_CHILDSYSTEM_EXPORT Q_DECL_IMPORT
#endif

class EntityList;
//外部数据 结构依赖
class ParameterData;
//mqtt 依赖
class MqttNetworkClicnt;
//qml connect
class QMLCmdConnecter;
class OM_CHILDSYSTEM_EXPORT ServicerChildSystem :public ISystem
{
    Q_OBJECT
public:
    explicit ServicerChildSystem();
    ~ServicerChildSystem();
    //启动
    virtual bool startSystem();
    virtual bool stopSystem();
signals:
    void signalGetFoodDataByType(const ParameterData& fromModel);
    void signalLoadModelDataSucc();
public slots:
    //从数据库 获取数据 然后设置到 系统数据源中
    void slotFromDatabaseFood(const QString& type,const EntityList& list);
    //设置前端qml 界面所需要的数据源
    virtual void initModelData();
private slots:
    void slotPublishMsg(const QString& msg);
private:
    void checkModelDataLoding(const int& value);

private:
    //界面显示的数据信息
    QList<QAbstractListModel*> m_modelList;
    /*quick view 加载界面 ui 的 engine*/
    QQmlApplicationEngine* m_qmlEngine = nullptr;
    //mqtt
    MqttNetworkClicnt*     m_mqttClient = nullptr;
    //
    QMLCmdConnecter*       m_pCmdConnect = nullptr;
};

#endif // OM_CHILDSYSTEM_SERVICERCHILDSYSTEM_H
