#ifndef SYSSERVICECONTROL_H
#define SYSSERVICECONTROL_H

#include <QObject>
#include <QAbstractListModel>
#include "sqlservice.h"
#include "qmlservice.h"

class SysServiceControl:public QObject
{
    Q_OBJECT
public:
    SysServiceControl(QObject* parent = nullptr);
    ~SysServiceControl();
    /*关闭服务*/
    bool closeService();
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
    SQLService* m_sql_service = nullptr;
    QMLService* m_qml_service = nullptr;
};

#endif // SYSSERVICECONTROL_H
