#ifndef SYSSERVICECONTROL_H
#define SYSSERVICECONTROL_H

#include <QObject>
#include <QQuickView>
#include "sql_service/sqlservice.h"

class SysServiceControl:public QObject
{
    Q_OBJECT
public:
    SysServiceControl(QObject* parent = nullptr);
    ~SysServiceControl();
signals:
    /*发出响应 登录ui 的信号 是否成功*/
    void signal_login_info(const int cmd);
    /*停止app*/
    void signal_stopApp(const int& type);
public slots:
    void slot_dealLogin(const QString name,const QString passwd);
private:
    /*初始化 服务/connect/UI*/
    bool init();
private:
    bool initServicerQMLUI();
private:
    SQLService* m_sql_service = nullptr;
    QQuickView* m_qml_view = nullptr;
    QQmlContext *m_ctx = nullptr;
};

#endif // SYSSERVICECONTROL_H
