#ifndef LOGINUI_H
#define LOGINUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QActionGroup>


struct UserInfo{
    QString userName;
    QString passwd;
    QString email;
};


namespace Ui {
class LoginUi;
}

class LoginUi : public QWidget
{
    Q_OBJECT
public:
    explicit LoginUi(QWidget *parent = nullptr);
    ~LoginUi();

    void init();
private:
    //UI界面设置  去边框，最小化，最大化button
    void configWindow();
    //isSandom is true,set img show by sandom
    void set_top_img(bool isSandom, int index_img);
    //设置UI上的按钮
    void set_button();
    //设置UI上用户头像
    void set_user_img(bool isSandom, int index_img);
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:
    void close();
private slots:

    void slot_timer1();
    void slot_timer2();
    void slot_minWindow();
    void slot_closeWindow();
    void slot_trayIcon();
    void slot_setLanguage();
    /*
    void on_cBox_account_activated(int index);
    void on_btn_login_clicked();
    void on_btn_regist_clicked();
    void on_btn_edit_pwd_clicked();
    void on_cBox_account_currentIndexChanged(int index);
    */
private:
    Ui::LoginUi *ui;
    bool m_Drag;
    QPoint m_point;
    QTimer *timer1;
    QTimer *timer2;
    //btn response
    QToolButton *minBtn;
    QToolButton *closeBbtn;
    QToolButton *setBtn;
    //System Tray Icon
    //SystemTrayIcon *trayIcon;
};

#endif // LOGINUI_H
