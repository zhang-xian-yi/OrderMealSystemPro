#include "loginui.h"
#include "ui_loginui.h"

#include <QTime>

#pragma execution_character_set("utf-8")

LoginUi::LoginUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginUi)
{
    ui->setupUi(this);

    m_Drag = false;
    init();
    connect(this,SIGNAL(close()),this,SLOT(close()));

    //设置最大窗口大小
    this->setMaximumSize(427,330);
    this->setMinimumSize(427,330);
    //隐藏任务栏图标
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowStaysOnTopHint | Qt::Tool;
    setWindowFlags(flags);
}

LoginUi::~LoginUi()
{
    if(nullptr != timer1)
    {
        delete timer1;
    }
    if(nullptr != timer2)
    {
        delete timer2;
    }
    //btn response
    if(nullptr != minBtn)
    {
        delete minBtn;
    }
    if(nullptr != closeBbtn)
    {
        delete closeBbtn;
    }
    if(nullptr != setBtn)
    {
        delete setBtn;
    }

    delete ui;
}


void LoginUi::init()
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
}

void LoginUi::configWindow()
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

void LoginUi::set_top_img(bool isSandom, int index_img)
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

void LoginUi::set_user_img(bool isSandom, int index_img)
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

void LoginUi::set_button()
{
    //构建最小化、关闭按钮,设置按钮，键盘ico
    minBtn = new QToolButton(this);
    closeBbtn = new QToolButton(this);
    setBtn = new QToolButton(this);

    //获取界面的宽度
    int width = this->width();
    //设置最小化、关闭按钮在界面的位置
    minBtn->setGeometry(width-55,5,20,20);
    closeBbtn->setGeometry(width-25,5,20,20);
    setBtn->setGeometry(width-80,7,15,15);

    //设置鼠标移至按钮上的提示信息
    minBtn->setToolTip(tr("最小化"));
    closeBbtn->setToolTip(tr("关闭"));
    setBtn->setToolTip(tr("设置"));

    //设置最小化、关闭按钮的样式图标
    minBtn->setIcon(QIcon(":/appfile/images/login/ico/mini.png"));
    minBtn->setStyleSheet("background-color:transparent;");
    closeBbtn->setIcon(QIcon(":/appfile/images/login/ico/close.png"));
    closeBbtn->setStyleSheet("background-color:transparent;");
    setBtn->setIcon(QIcon(":/appfile/images/login/ico/setting.png"));
    setBtn->setStyleSheet("background-color:transparent;");

    //关联最小化、关闭按钮的槽函数,键盘exe
    connect(minBtn, SIGNAL(clicked()), this, SLOT(slot_minWindow()));
    connect(closeBbtn, SIGNAL(clicked()), this, SLOT(slot_closeWindow()));
    connect(setBtn, SIGNAL(clicked()), this, SLOT(slot_setLanguage()));
}


//鼠标事件的响应
void LoginUi::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_Drag = true;
        m_point = e->globalPos() - this->pos();
        e->accept();
    }
}

void LoginUi::mouseMoveEvent(QMouseEvent *e)
{
    if (m_Drag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - m_point);
        e->accept();
    }
}

void LoginUi::mouseReleaseEvent(QMouseEvent *e)
{
    m_Drag = false;
}


//slot function
void LoginUi::slot_minWindow()
{
    this->showMinimized();
}

void LoginUi::slot_setLanguage()
{
    static QMenu setTool;
    static QAction act_chinese(tr("Chinese"), this);
    static QAction act_english(tr("English"), this);

    setTool.addAction(&act_chinese);
    setTool.addAction(&act_english);
    setTool.exec(QCursor::pos());
}

//关闭程序 应该放在app 中进行调用
void LoginUi::slot_closeWindow()
{
    this->close();
    timer2->start(3);
}

void LoginUi::slot_trayIcon()
{
    timer1->start(5);
}

void LoginUi::slot_timer1()
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

void LoginUi::slot_timer2()
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

