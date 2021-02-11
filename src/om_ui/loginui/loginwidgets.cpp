#include "loginwidgets.h"
#include "ui_loginwidgets.h"

#include <QThread>
#include <QTime>
#include <QDesktopServices>
//依赖其他模块
#include "../om_common/commoninc/debugdefine.h"
#include "../om_common/utils/confighelperutil/confighelperutil.h"



LoginWidgets::LoginWidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidgets)
{
    ui->setupUi(this);

    m_Drag = false;
    init();
    //设置最大窗口大小
    this->setMaximumSize(427,330);
    this->setMinimumSize(427,330);
    //关闭窗口释放内存
    this->setAttribute(Qt::WA_DeleteOnClose);
    //隐藏任务栏图标
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowStaysOnTopHint | Qt::Tool;
    setWindowFlags(flags);
}

LoginWidgets::~LoginWidgets()
{
    closeWindows();
    if(nullptr != ui)
    {
        delete ui;
        ui = nullptr;
    }
}

void LoginWidgets::closeWindows()
{
    if(nullptr != timer1)
    {
        timer1->stop();
        delete timer1;
        timer1 = nullptr;
    }
    if(nullptr != timer2)
    {
        timer2->stop();
        delete timer2;
        timer2 = nullptr;
    }
    //btn response
    if(nullptr != minBtn)
    {
        delete minBtn;
        minBtn = nullptr;
    }
    if(nullptr != closeBtn)
    {
        delete closeBtn;
        closeBtn = nullptr;
    }
    if(nullptr != setBtn)
    {
        delete setBtn;
        setBtn = nullptr;
    }
}


void LoginWidgets::init()
{
    setWindowTitle(tr("登录"));

    timer1 = new QTimer();
    timer1->start(5);
    timer2 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(slot_timer1()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(slot_timer2()));
    //UI界面设置  去边框，最小化，最大化button
    configWindow();

    //init记住密码
    ui->checkBox_rPasswd->setChecked(true);
    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);
    //init connect
    init_connect_func();
}

void LoginWidgets::init_connect_func()
{
    //connect(ui->cBox_account,SIGNAL(clicked()),this,SLOT(on_cBox_account_activated(int)));
    connect(ui->btn_login,SIGNAL(clicked()),this,SLOT(on_btn_login_clicked()));
    connect(this,SIGNAL(destroyed(QObject *)),this,SLOT(closeWindows( )));
}

void LoginWidgets::configWindow()
{
    // 填充背景图片
    QPalette palette;
    palette.setBrush(/*QPalette::Background*/this->backgroundRole(),
                      //QBrush(QPixmap(":appfile/images/login/QQ1.png")));
                        QBrush(QPixmap(":/appfile/images/login/background.png")));
    this->setPalette(palette);
    //去掉窗口边框
    setWindowFlags(Qt::FramelessWindowHint);
    //设置图片显示为随机显示
    set_top_img(true, -1);
    //设置user图片为随机显示
    set_user_img(true, -1);
    //设置UI的按钮button
    set_button();
}

void LoginWidgets::set_top_img(bool isSandom, int index_img)
{
    //427 185
    int set_index_img = 1;
    if(isSandom == true)//随机显示topimg
    {
        QTime time_sand;
        time_sand= QTime::currentTime();//获取当前时间
        qsrand(time_sand.msec()+time_sand.second()*1000);
        //在1-5中选出随机数
        set_index_img = qrand()%5 + 1 ;
    }
    //不随机显示，按index_img显示图片s
    if(isSandom == false)
    {
        set_index_img = index_img;
    }
    QString top_img_path=":/appfile/images/login/top_img1.png";
    QImage top_img;
    top_img_path = ":/appfile/images/login/top_img" + QString::number(set_index_img, 10)  + ".png";
    top_img.load(top_img_path);
    QPixmap top_pic=QPixmap::fromImage(top_img.scaled(ui->label_top_img->width(),ui->label_top_img->height()));
    ui->label_top_img->setPixmap(top_pic);
}

void LoginWidgets::set_user_img(bool isSandom, int index_img)
{
    //40,182 85 85
    int set_index_img = 1;
    if(isSandom == true)//随机显示userimg
    {
        QTime time_sand;
        time_sand= QTime::currentTime();//获取当前时间
        qsrand(time_sand.msec()+time_sand.second()*1000);
        set_index_img = qrand()%5 + 1 ;//在1-5中选出随机数
    }
    //不随机显示，按index_img显示图片s
    if(isSandom == false)
    {
        set_index_img = index_img;
    }

    QString user_img_path=":/appfile/images/login/ico/user1.png";

    QImage user_img;
    user_img_path = ":/appfile/images/login/ico/user" + QString::number(set_index_img, 10)  + ".png";
    user_img.load(user_img_path);
    QPixmap img_pic=QPixmap::fromImage(user_img.scaled(ui->label_user_img->width(),
                                                       ui->label_user_img->height()));
    ui->label_user_img->setPixmap(img_pic);
}

void LoginWidgets::set_button()
{
    //构建最小化、关闭按钮,设置按钮，键盘ico
    minBtn = new QToolButton(this);
    closeBtn = new QToolButton(this);
    setBtn = new QToolButton(this);

    //获取界面的宽度
    int width = this->width();
    //设置最小化、关闭按钮在界面的位置
    minBtn->setGeometry(width-55,5,20,20);
    closeBtn->setGeometry(width-25,5,20,20);
    setBtn->setGeometry(width-80,7,15,15);

    //设置鼠标移至按钮上的提示信息
    minBtn->setToolTip(tr("最小化"));
    closeBtn->setToolTip(tr("关闭"));
    setBtn->setToolTip(tr("设置"));

    //设置最小化、关闭按钮的样式图标
    minBtn->setIcon(QIcon(":/appfile/images/login/ico/mini.png"));
    minBtn->setStyleSheet("background-color:transparent;");
    closeBtn->setIcon(QIcon(":/appfile/images/login/ico/close.png"));
    closeBtn->setStyleSheet("background-color:transparent;");
    setBtn->setIcon(QIcon(":/appfile/images/login/ico/setting.png"));
    setBtn->setStyleSheet("background-color:transparent;");

    //关联最小化、关闭按钮的槽函数,键盘exe
    connect(minBtn, SIGNAL(clicked()), this, SLOT(slot_minWindow()));
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(slot_closeWindow()));
    connect(setBtn, SIGNAL(clicked()), this, SLOT(slot_setLanguage()));
}


//鼠标事件的响应
void LoginWidgets::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_Drag = true;
        m_point = e->globalPos() - this->pos();
        e->accept();
    }
}

void LoginWidgets::mouseMoveEvent(QMouseEvent *e)
{
    if (m_Drag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - m_point);
        e->accept();
    }
}

void LoginWidgets::mouseReleaseEvent(QMouseEvent *e)
{
    m_Drag = false;
}


//slot function
void LoginWidgets::slot_minWindow()
{
    this->showMinimized();
}

void LoginWidgets::slot_setLanguage()
{
    static QMenu setTool;
    static QAction act_chinese(tr("Chinese"), this);
    static QAction act_english(tr("English"), this);

    setTool.addAction(&act_chinese);
    setTool.addAction(&act_english);
    setTool.exec(QCursor::pos());
}

//关闭程序 应该放在app 中进行调用
#define NORMAL_EXIT 3
void LoginWidgets::slot_closeWindow()
{
    timer2->start(3);
    closeWindows();
    emit signal_stopApp(NORMAL_EXIT);
}

void LoginWidgets::slot_trayIcon()
{
    timer1->start(5);
}

void LoginWidgets::slot_timer1()
{
    static double opacity1 = 0.0;
    if (opacity1 >= 1.0)
    {
        timer1->stop();
    }
    else
    {
        opacity1 += 0.01;
    }
    setWindowOpacity(opacity1);//设置窗口透明度
}

void LoginWidgets::slot_timer2()
{
    static double opacity2 = 0.0;
    if (opacity2 <= 0.0)
    {
        timer2->stop();
        this->close();
    }
    else
    {
        opacity2 -= 0.01;
    }
    setWindowOpacity(opacity2);//设置窗口透明度
}



//下拉框选里面的项时，会切换top_img的图片和头像图片
void LoginWidgets::on_cBox_account_currentIndexChanged(int index)
{
   static int flag = -1;
   //如果相同就无需在进行替换图片了
   if(flag == index)
   {
       flag = index;
       return;
   }
   set_top_img(true,index);
   set_user_img(true,index);
}

void LoginWidgets::on_btn_login_clicked()
{
    QString username = ui->cBox_account->currentText();
    QString passwd = ui->lineEdit_passwd->text();
    DEBUG_UI("username:%s,password:%s,",username.toStdString().c_str(),passwd.toStdString().c_str());
    emit signalLoginBtnClick(username,passwd);
}

void LoginWidgets::on_btn_regist_clicked()
{
    QString str_url =ConfigHelperUtil::getInstance()->getValue("LoginConfig","register_url");
    //default config status
    if(str_url.isEmpty())
    {
        str_url = "http://www.zhangxianyi4work.work/registered.html";
    }
    QDesktopServices::openUrl(QUrl(str_url));
}
void LoginWidgets::on_btn_edit_pwd_clicked()
{
    QString str_url =ConfigHelperUtil::getInstance()->getValue("LoginConfig","login_url");
    //default config status
    if(str_url.isEmpty())
    {
        str_url = "http://www.zhangxianyi4work.work/login.html";
    }
    QDesktopServices::openUrl(QUrl(str_url));
}


