#ifndef SERVICERSYSTEM_H
#define SERVICERSYSTEM_H

#include "../isystem.h"
#include <QAbstractListModel>

class ServicerSystem : public ISystem
{
    Q_OBJECT
public:
    explicit ServicerSystem();
    ~ServicerSystem();
    /*启动服务管理的子系统*/
    virtual bool start()override;
    virtual bool stop() override;
private:
    bool initServicerContext();
    bool inittypeData();
private:
    QList<QAbstractListModel*> m_model_list;
};

#endif // SERVICERSYSTEM_H
