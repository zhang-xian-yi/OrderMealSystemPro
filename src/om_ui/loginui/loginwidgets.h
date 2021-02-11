#ifndef LOGINWIDGETS_H
#define LOGINWIDGETS_H

#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QObject>

namespace Ui {
class LoginWidgets;
}

class LoginWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidgets(QWidget *parent = nullptr);
    ~LoginWidgets();
public slots:
    void closeWindows();
private:
    //初始化
    void init();
    /*UI界面设置  去边框，最小化，最大化button*/
    void configWindow();
    /*isSandom is true,set img show by sandom*/
    void set_top_img(bool isSandom, int index_img);
    /*设置UI上的按钮*/
    void set_button();
    /*设置UI上用户头像*/
    void set_user_img(bool isSandom, int index_img);
    /*初始化 connct 函数*/
    void init_connect_func();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:
    void signal_stopApp(const int& type);
    void signalLoginBtnClick(const QString name,const QString passwd);
private slots:

    void slot_timer1();
    void slot_timer2();
    void slot_minWindow();
    void slot_closeWindow();
    void slot_trayIcon();
    void slot_setLanguage();

    // response func
    void on_btn_login_clicked();
    void on_btn_regist_clicked();
    void on_btn_edit_pwd_clicked();
    void on_cBox_account_currentIndexChanged(int index);
private:
    Ui::LoginWidgets *ui;
    bool m_Drag;
    QPoint m_point;
    QTimer *timer1;
    QTimer *timer2;
    //btn response
    QToolButton *minBtn;
    QToolButton *closeBtn;
    QToolButton *setBtn;
};


#endif // LOGINWIDGETS_H
