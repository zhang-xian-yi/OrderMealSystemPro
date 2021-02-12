#ifndef OM_UI_LOGINUI_LOGINGUI_H
#define OM_UI_LOGINUI_LOGINGUI_H
#include "../igui.h"

#include <QtCore/qglobal.h>
#if defined(OM_UI_LIBRARY)
#  define OM_UI_EXPORT Q_DECL_EXPORT
#else
#  define OM_UI_EXPORT Q_DECL_IMPORT
#endif

//login ui 的具体处理逻辑 与 界面
class ParameterData;
class LoginWidgets;
class OM_UI_EXPORT LoginGUI:public IGui
{
    Q_OBJECT
public:
    explicit LoginGUI();
    virtual ~LoginGUI() override;
    virtual int startGui() override;
    virtual int stopGui() override;
signals:
    void signalLogin(const ParameterData& UserInfo);
    void signalAppExit();
public slots:
    void slotResponseLoginFailed(const ParameterData& info);
private slots:
    void slotLoginBtnClick(const QString& username,const QString& pass);
private:
    LoginWidgets* m_loginUI;
};

#endif // OM_UI_LOGINUI_LOGINGUI_H
