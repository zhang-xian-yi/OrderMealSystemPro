#-------------------------------------------------
#
# Project created by QtCreator 2021-01-16T09:03:23
#
#-------------------------------------------------

#TARGET = OrderMealSystemPro
TEMPLATE = subdirs
#pro 文件 定义
om_ui.file = $$PWD/src/om_ui/om_ui.pro
om_common.file = $$PWD/src/om_common/om_common.pro
om_databases.file = $$PWD/src/om_databases/om_databases.pro
om_network.file = $$PWD/src/om_network/om_network.pro
om_centralcontrol.file = $$PWD/src/om_centralcontrol/om_centralcontrol.pro
om_childsystem.file = $$PWD/src/om_childsystem/om_childsystem.pro
om_core.file = $$PWD/src/om_core/om_core.pro

#dependes 关系
om_ui.depends += om_common
om_databases.depends += om_common
om_centralcontrol.depends += om_common om_databases
om_core.depends += om_common om_datamodel om_ui om_css
om_childsystem.depends += om_common om_ui


SUBDIRS += \
    $$PWD/src/om_ui \
    $$PWD/src/om_common \
    $$PWD/src/om_core \
    $$PWD/src/om_databases \
    $$PWD/src/om_centralcontrol \
    $$PWD/src/om_childsystem \
    $$PWD/src/om_network

CONFIG += c++11
CONFIG -= qml_debug
#屏蔽 与项目无关的库
win32-msvc*:QMAKE_CXXFLAGS += /wd"4819"




# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target


