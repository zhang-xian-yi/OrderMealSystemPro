#ifndef ISYSTEM_H
#define ISYSTEM_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include "qml_service/qml_connect/qmlconnecter.h"

/*模板工厂通过 int 类型识别生产的对象  从2 开始避免与其他的类型进行冲突*/
/*一台机器上只会存在一个系统处于运行态*/
namespace SystemTypeSpace {
enum SystemType{
  Service_System = 2,
  Cooker_System,
};
}



 /*保证子系统拥有 启动/停止 功能 */
class ISystem:public QObject
{
public:
    /*构造函数*/
    ISystem();
    /*启动一个子系统*/
    virtual bool start() = 0;
    /*停止子系统的运行*/
    virtual bool stop() = 0;
    /*析构函数必须设置为虚函数*/
    virtual ~ISystem();
    /*获取 QML connector 的指针*/
    QMLCmdConnecter* getCmdConnect()const;
private:
    /*初始化上下文*/
    bool initContext();
protected:
    /*quick view 加载界面 ui 的view*/
    QQmlApplicationEngine * m_qml_engine = nullptr;
    /*链接对象*/
    QMLCmdConnecter* m_cmd_connect = nullptr;
};


#endif // ISYSTEM_H
