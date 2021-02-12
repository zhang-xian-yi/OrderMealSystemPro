#include <QMessageBox>
#include "logingui.h"
#include "loginui/loginwidgets.h"
#include "../om_common/datastruct/datastructs.h"


LoginGUI::LoginGUI()
{
    m_loginUI = new LoginWidgets;
    connect(m_loginUI,&LoginWidgets::signalLoginBtnClick,this,&LoginGUI::slotLoginBtnClick);
    connect(m_loginUI,&LoginWidgets::signal_stopApp,this,&LoginGUI::signalAppExit);
}

LoginGUI::~LoginGUI()
{
    if(nullptr != m_loginUI)
    {
        delete m_loginUI;
        m_loginUI = nullptr;
    }
}

int LoginGUI::startGui()
{
    m_loginUI->show();
    return 0;
}

int LoginGUI::stopGui()
{
    return m_loginUI->close();
}
/**
* @brief: 接受 控制中心传来的登录错误信息
* @param：
* @return:
* @date: 2021-02-12
*/
void LoginGUI::slotResponseLoginFailed(const ParameterData &info)
{
    QString errorInfo = info.getValue("msg");
    QMessageBox::warning(m_loginUI,QStringLiteral("登录失败"),errorInfo);
}
/**
* @brief: 登录按钮的响应函数
* @param：username 用户名
* @return: pass 密码
* @date: 2021-02-08
*/
void LoginGUI::slotLoginBtnClick(const QString &username, const QString &pass)
{
    static ParameterData data;
    data.clear();
    data.appendItem("username",username);
    data.appendItem("password",pass);
    emit signalLogin(data);
}
