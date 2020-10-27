
QT  += sql


include($$PWD/sqlite/sqlite.pri)
include($$PWD/mysql/mysql.pri)

INCLUDEPATH += $$PWD/sqlite/
INCLUDEPATH += $$PWD/mysql/
INCLUDEPATH += $$PWD/

HEADERS += \
        $$PWD/sqlglobal.h



