#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

class SystemTrayIcon : public QWidget
{
    Q_OBJECT
public:
    explicit SystemTrayIcon(QStringList strList, QIcon icon,QWidget* parent = nullptr);
    ~SystemTrayIcon();
    bool setParentWidget(QWidget* parent);
    void createAct();
    void createTrayMenu();
    void createTrayIcon();
    bool closeTrayIcon();

signals:
    void signal_showWin();          //显示窗口
    void signal_stopApp(const int& type);
public slots:
    void slot_iconActivated(QSystemTrayIcon::ActivationReason reason);
    void slot_app_exit();
private:
    QSystemTrayIcon *m_trayIcon = nullptr;        //系统托盘
    QMenu *menu = nullptr;                        //菜单
    QAction *actMin = nullptr;                    //最小化
    QAction *actNormal = nullptr;                 //正常
    QAction *actExit = nullptr;                   //退出

    QStringList m_strList;                //托盘信息
    QIcon m_icon;                         //托盘图标
    QWidget *pWidget = nullptr;
};

#endif // SYSTEMTRAYICON_H
