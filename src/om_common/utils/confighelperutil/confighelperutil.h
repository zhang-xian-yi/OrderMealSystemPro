#ifndef CONFIGHELPERUTIL_H
#define CONFIGHELPERUTIL_H

#include <QSettings>
#include <QSharedPointer>
#include <QDir>

#include <QtCore/qglobal.h>
#if defined(OM_COMMON_LIBARAY)
#  define OM_COMMON_EXPORT Q_DECL_EXPORT
#else
#  define OM_COMMON_EXPORT Q_DECL_IMPORT
#endif

class OM_COMMON_EXPORT ConfigHelperUtil
{
public:
    //get the config readutil   bean
    static ConfigHelperUtil* getInstance()
    {
        QString filepath = QDir::currentPath();
        filepath += "/sysConfig.ini";
        static ConfigHelperUtil instance(filepath);
        return &instance;
    }
    //remove node (include its all key-value pair)
    void removeNode(const QString &section);
    //remove the key
    void removeKey(const QString &section, const QString &key);
    //Reads the value from the configuration file based on nodes and key values
    QString getValue(const QString& section,const QString& key);
    //Writes the node and the key-value pair to the configuration file
    void    setValue(const QString& section,const QString& key,const QString& value);
    //clear all config
    void clearConfig();
    void initSetting(const QString &path);
private:
    // Forbid external construction
    ConfigHelperUtil(const QString &path);
    // External destructions are prohibited
    ~ConfigHelperUtil();
    // External replication constructs are prohibited
    ConfigHelperUtil(const ConfigHelperUtil &)=delete;
    // Prohibit external assignment operations
    ConfigHelperUtil &operator=(ConfigHelperUtil &)=delete;
private:
    QSharedPointer<QSettings> m_ini_file;
};


// Encryption program






#endif // CONFIGHELPERUTIL_H
