#ifndef OM_UI_IGUI_H
#define OM_UI_IGUI_H

#include <QObject>
#include <QtCore/qglobal.h>
#if defined(OM_UI_LIBRARY)
#  define OM_UI_EXPORT Q_DECL_EXPORT
#else
#  define OM_UI_EXPORT Q_DECL_IMPORT
#endif


namespace GUISpace
{
enum GUIType
{
    E_LOGING_GUI = 0,
    E_SERVICER_GUI,
    E_COOKER_GUI
};
}

class BaseStruct;

//启动gui 的接口
class OM_UI_EXPORT IGui:public QObject
{
    Q_OBJECT
public:
    virtual ~IGui(){}
    virtual int startGui() = 0;
    virtual int stopGui() = 0;
};


#endif // OM_UI_IGUI_H
