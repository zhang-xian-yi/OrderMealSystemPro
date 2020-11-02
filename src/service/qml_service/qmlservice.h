#ifndef QMLSERVICE_H
#define QMLSERVICE_H
#include <QObject>
#include "qml_system/isystem.h"

class QMLService:public QObject
{
    Q_OBJECT
public:
    explicit QMLService();
    ~QMLService();

    /*启动子系统*/
    bool startChildSystem();
    /*停止子系统*/
    bool stopChildSystem();
    void setSystemType(const int& type);
private:
    bool initContext();
private:
    ISystem* m_child_system = nullptr;
    int m_system_type;
};

#endif // QMLSERVICE_H
