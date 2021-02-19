QT  += qml
TARGET = om_ui
TEMPLATE = lib

DEFINES = OM_UI_LIBRARY

include($$PWD/loginui/loginui.pri)
include($$PWD/servicerui/servicerui.pri)
include($$PWD/systemtrayicon/systemtrayicon.pri)

HEADERS += \
    igui.h
# add include search path
INCLUDEPATH += $$PWD/
# generate file path
MOC_DIR = $$PWD/../../generatedFile/temp/moc
RCC_DIR = $$PWD/../../generatedFile/temp/rcc
OBJECTS_DIR = $$PWD/../../generatedFile/temp/obj
UI_HEADERS_DIR = $$PWD/../../generatedFile/temp/ui
DESTDIR = $$PWD/../../generatedFile/destdir
DLLDESTDIR = $$PWD/../../generatedFile/bin


LIBS += -L$$PWD/../../generatedFile/destdir -lom_common

#资源文件
RESOURCES +=  $$PWD/../../appfile/qrc/login.qrc
#防止release 版本下 资源文件不存在
QTQUICK_COMPILER_SKIPPED_RESOURCES += $$PWD/../../qml.qrc
RESOURCES +=  $$PWD/../../qml.qrc

RESOURCES +=  $$PWD/../../appfile/qrc/startApp.qrc
