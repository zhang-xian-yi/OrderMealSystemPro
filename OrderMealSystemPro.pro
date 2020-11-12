#-------------------------------------------------
#
# Project created by QtCreator 2020-06-01T19:15:10
#
#-------------------------------------------------

QT       += core gui network
QT       += qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = OrderMeal


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#include path


#module
include(src/public/public.pri)
include(src/mainapp/mainapp.pri)
include(src/ui/ui.pri)
include(src/utils/utils.pri)
include(src/entity/entity.pri)
include(src/service/service.pri)
include(src/databases/databases.pri)

# generate file path
MOC_DIR = $$PWD/CompileTheGeneratedFile/temp/moc
RCC_DIR = $$PWD/CompileTheGeneratedFile/temp/rcc
OBJECTS_DIR = $$PWD/CompileTheGeneratedFile/temp/obj
UI_HEADERS_DIR = $$PWD/CompileTheGeneratedFile/temp/ui
DESTDIR = $$PWD/CompileTheGeneratedFile/bin

OUT_PWD = $$PWD/CompileTheGeneratedFile/bin

LIBS += -L $$OUT_PWD/lib/sql/ -llibmysql
LIBS += -L$$OUT_PWD/lib/mqtt/ -lQt5Mqtt


#资源文件
win32:RC_FILE = $$PWD/appfile/qrc/OrderMeal.rc
RESOURCES += $$PWD/appfile/qrc/login.qrc
RESOURCES += $$PWD/qml.qrc
RESOURCES += $$PWD/appfile/qrc/startApp.qrc


#x消息打印
#message($$PWD)
#message($$DESTDIR)
#message($$TARGET)
