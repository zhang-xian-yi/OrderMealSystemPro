#include <QFile>
#include <QTextCodec>

#include "confighelperutil.h"
#include "encryputil.h"
#include "global.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

ConfigHelperUtil::ConfigHelperUtil(const QString& filepath)
{
    EncrypUtil::decryptFile(filepath);
    initSetting(filepath);
}

ConfigHelperUtil::~ConfigHelperUtil()
{
}

void ConfigHelperUtil::initSetting(const QString &path)
{
    QString fileName;
    fileName = QCoreApplication::applicationDirPath();
    fileName += path;
    TRACE("file name: %s",fileName.toLatin1().data());
    QFile file(path);
    if(file.exists())
    {
        TRACE("file exist");
        m_ini_file = QSharedPointer<QSettings>(new QSettings(path, QSettings::IniFormat));
        //Make sure Chinese can be used
        m_ini_file->setIniCodec(QTextCodec::codecForName("System"));
    }
    //Open the file read-only and create it if it doesn't exist
    if (false == file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        m_ini_file->beginGroup("configFile");
        m_ini_file->setValue("path", "NOT_EXIST");
        m_ini_file->endGroup();
    }
}

void ConfigHelperUtil::setValue(const QString &section, const QString &key, const QString &value)
{
    //encryp operation

    // set section name
    m_ini_file->beginGroup(section);
    //set key-value
    m_ini_file->setValue(key, value);
    // end current section operation
    m_ini_file->endGroup();
}

void ConfigHelperUtil::removeNode(const QString &section)
{
    //Make sure Chinese can be used
    //m_ini_file->setIniCodec(QTextCodec::codecForName("System"));
    m_ini_file->remove(section);
}

void ConfigHelperUtil::removeKey(const QString &section, const QString &key)
{
    /*
    QString path = QString("%1/%2").arg(section).arg(key);
    m_ini_file->remove(path);
    */
    // start the section oper
    m_ini_file->beginGroup(section);
    m_ini_file->remove(key);
    m_ini_file->endGroup();
}

QString ConfigHelperUtil::getValue(const QString &section, const QString &key)
{
    QString path = QString("%1/%2").arg(section).arg(key);
    QString result = m_ini_file->value(path).toString();
    return result;
}

