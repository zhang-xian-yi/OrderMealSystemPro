QT  += core qml
#常驻内存的数据源
TEMPLATE = lib
TARGET = om_childsystem

DEFINES = OM_CHILDSYSTEM_LIBARAY


include($$PWD/servicersystem/servicersystem.pri)
include($$PWD/common/common.pri)

INCLUDEPATH += $$PWD/
#外部依赖数据
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_common
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_ui
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_network

# generate file path
MOC_DIR = $$PWD/../../generatedFile/temp/moc
RCC_DIR = $$PWD/../../generatedFile/temp/rcc
OBJECTS_DIR = $$PWD/../../generatedFile/temp/obj
UI_HEADERS_DIR = $$PWD/../../generatedFile/temp/ui
DESTDIR = $$PWD/../../generatedFile/destdir
DLLDESTDIR = $$PWD/../../generatedFile/bin

HEADERS += \
    isystem.h

SOURCES += \
    isystem.cpp
