#-------------------------------------------------
#
# Project created by QtCreator 2020-06-01T19:15:10
#
#-------------------------------------------------

QT       += core gui network

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
INCLUDEPATH += $$PWD/src/mainapp/
INCLUDEPATH += $$PWD/src/public/
INCLUDEPATH += $$PWD/src/ui/login/
INCLUDEPATH += $$PWD/src/ui/systemtrayicon/
INCLUDEPATH += $$PWD/src/utils/confighelperutil/
INCLUDEPATH += $$PWD/src/utils/encryputil/

#module
include(src/public/public.pri)
include(src/mainapp/mainapp.pri)
include(src/ui/ui.pri)
include(src/utils/utils.pri)

# generate file path
MOC_DIR = $$PWD/CompileTheGeneratedFile/temp/moc
RCC_DIR = $$PWD/CompileTheGeneratedFile/temp/rccr
OBJECTS_DIR = $$PWD/CompileTheGeneratedFile/temp/obj
UI_HEADERS_DIR = $$PWD/CompileTheGeneratedFile/temp/ui
DESTDIR = $$PWD/CompileTheGeneratedFile/bin


#资源文件
win32:RC_FILE = $$PWD/OrderMeal.rc
RESOURCES += $$PWD/login.qrc
RESOURCES += $$PWD/startApp.qrc
