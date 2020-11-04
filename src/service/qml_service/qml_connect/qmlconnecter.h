#ifndef QMLCONNECTER_H
#define QMLCONNECTER_H

#include <QObject>
#include "qml_service/beanfactory.h"

namespace CmdTypeSpace {
enum CmdType{
    Servicer_Submit_FoodList = 1,
    Cooker_Finish_One
};
}


class QMLCmdConnecter : public QObject
{
    Q_OBJECT
public:
    explicit QMLCmdConnecter(QObject *parent = nullptr);
    /*初始化*/
    bool init();
public:
    Q_INVOKABLE void handleCmd(const int& cmd,const QString& content);
signals:
    void signal_cmd(const int& cmd);
public slots:
public:

private:
    bool m_app_run;
};

#endif // QMLCONNECTER_H
