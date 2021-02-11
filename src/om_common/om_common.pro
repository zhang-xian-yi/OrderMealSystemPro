
TEMPLATE = lib
TARGET = om_common

DEFINES = OM_COMMON_LIBARAY


include($$PWD/commoninc/commoninc.pri)
include($$PWD/utils/utils.pri)
include($$PWD/datastruct/datastruct.pri)

INCLUDEPATH += $$PWD/

# generate file path
MOC_DIR = $$PWD/../../generatedFile/temp/moc
RCC_DIR = $$PWD/../../generatedFile/temp/rcc
OBJECTS_DIR = $$PWD/../../generatedFile/temp/obj
UI_HEADERS_DIR = $$PWD/../../generatedFile/temp/ui
DESTDIR = $$PWD/../../generatedFile/destdir
DLLDESTDIR = $$PWD/../../generatedFile/bin



