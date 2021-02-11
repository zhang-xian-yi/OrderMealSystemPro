#ifndef ENCRYPUTIL_H
#define ENCRYPUTIL_H

#include <QString>

#include <QtCore/qglobal.h>
#if defined(OM_COMMON_LIBARAY)
#  define OM_COMMON_EXPORT Q_DECL_EXPORT
#else
#  define OM_COMMON_EXPORT Q_DECL_IMPORT
#endif

class EncrypUtil
{
public:
    //return null is failed
    static void encryptFile(const QString& filepath);
    static void decryptFile(const QString& filepath);
};
#endif // ENCRYPUTIL_H
