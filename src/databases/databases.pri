
QT  += sql


include($$PWD/sqlite/sqlite.pri)
include($$PWD/mysql/mysql.pri)

INCLUDEPATH += $$PWD/

HEADERS += \
        $$PWD/sqlglobal.h



