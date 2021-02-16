#ifndef OM_CCS_CENTRALCONTROLSYS_H
#define OM_CCS_CENTRALCONTROLSYS_H
#include <QObject>
#include <QString>

#include <QtCore/qglobal.h>
#if defined(OM_CCS_LIBARAY)
#  define OM_CSS_EXPORT Q_DECL_EXPORT
#else
#  define OM_CSS_EXPORT Q_DECL_IMPORT
#endif


//外部数据引用
class ParameterData;
class EntityList;
//处理具体业务逻辑的类
class CCSPrivate;
class OM_CSS_EXPORT CentralControlSys:public QObject
{
    Q_OBJECT
public:
    //单例获取指针
    static CentralControlSys* getInstance();
public:
signals:
    void signalResponseLoginSucc(const ParameterData& data);
    void signalResponseLoginFailed(const ParameterData& data);
    void signalResponseModelRequest(const QString& tpye,const EntityList& dataSource);
public slots:
    void slotLogin(const ParameterData& fromUI );
    void slotGetFoodDataByTypeFromDatabase(const ParameterData& fromModel);
private:
    // Forbid external construction
    CentralControlSys();
    // External destructions are prohibited
    ~CentralControlSys();
    // External replication constructs are prohibited
    CentralControlSys(const CentralControlSys &)=delete;
    // Prohibit external assignment operations
    CentralControlSys &operator=(CentralControlSys &)=delete;
private:
    CCSPrivate* m_servicePrivate;
};

#endif // OM_CCS_CENTRALCONTROLSYS_H
