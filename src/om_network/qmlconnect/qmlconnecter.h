#ifndef QMLCONNECTER_H
#define QMLCONNECTER_H

#include <QObject>
namespace CmdTypeSpace {
enum CmdType{
    Servicer_Submit_FoodList = 1,
    Cooker_Finish_One
};
}
#include <QtCore/qglobal.h>
#if defined(OM_NETWORK_LIBARAY)
#  define OM_NETWORK_EXPORT Q_DECL_EXPORT
#else
#  define OM_NETWORK_EXPORT Q_DECL_IMPORT
#endif

class OM_NETWORK_EXPORT QMLCmdConnecter : public QObject
{
    Q_OBJECT
public:
    explicit QMLCmdConnecter(QObject *parent = nullptr);
public:
    Q_INVOKABLE void handleCmd(const int& cmd,const QString& content);
signals:
    void signal_cmd(const int& cmd);
    void signalSubmitFoodList(const QString& foodList);
private:

};

#endif // QMLCONNECTER_H
