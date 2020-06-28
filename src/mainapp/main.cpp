#include "ordermealapp.h"
#include <QApplication>

#include "loginui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OrderMealApp w;

    w.startApp();

    return a.exec();
}
