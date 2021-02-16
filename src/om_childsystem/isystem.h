#ifndef ISYSTEM_H
#define ISYSTEM_H

#include <QObject>
#include <QMap>
#include <QString>

class ISystem:public QObject
{
    Q_OBJECT
public:
    enum EChildSystemType
    {
        E_SERVICER_SYSTEM = 2,
        E_COUNTER_SYSTEM,
        E_COOKER_SYSTEM,
        E_MANAGER_SYSTEM
    };
public:
    explicit ISystem();
    virtual ~ISystem();
    virtual bool startSystem() = 0;
    virtual bool stopSystem() = 0;
    virtual void initModelData() = 0;
private:
    static QMap<QString,QString> m_errorMsg;
};

#endif // ISYSTEM_H
