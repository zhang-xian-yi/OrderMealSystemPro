#ifndef ENCRYPUTIL_H
#define ENCRYPUTIL_H

#include <QString>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#define ENCRYP_MAX_SIZE     128
#include <string.h>

class EncrypUtil
{
public:
    //return null is failed
    static void encryptFile(const QString& filepath);
    static void decryptFile(const QString& filepath);
};
#endif // ENCRYPUTIL_H
