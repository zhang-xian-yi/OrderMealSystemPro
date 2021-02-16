QT       += core gui qml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = OrderMealSystem
TEMPLATE = app

#内部文件
include($$PWD/mainapp/mainapp.pri)
include($$PWD/application/application.pri)
#内部路径
INCLUDEPATH += $$PWD/

ROOT_PATH = $$PWD/../../
#资源文件
win32:RC_FILE = $$ROOT_PATH/appfile/qrc/OrderMeal.rc

#外部依赖模块
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_common
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_childsystem
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_databases
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_ui
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_centralcontrol




# generate file path
MOC_DIR = $$PWD/../../generatedFile/temp/moc
RCC_DIR = $$PWD/../../generatedFile/temp/rcc
OBJECTS_DIR = $$PWD/../../generatedFile/temp/obj
UI_HEADERS_DIR = $$PWD/../../generatedFile/temp/ui
DESTDIR = $$PWD/../../generatedFile/bin

