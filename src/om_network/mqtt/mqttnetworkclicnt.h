#ifndef OM_NETWORK_MQTTNETWORKCLICNT_H
#define OM_NETWORK_MQTTNETWORKCLICNT_H

#include <QObject>

#include <QtCore/qglobal.h>
#if defined(OM_NETWORK_LIBARAY)
#  define OM_NETWORK_EXPORT Q_DECL_EXPORT
#else
#  define OM_NETWORK_EXPORT Q_DECL_IMPORT
#endif

#include <QtCore/qglobal.h>
#if defined(OM_NETWORK_LIBARAY)
#  define OM_NETWORK_EXPORT Q_DECL_EXPORT
#else
#  define OM_NETWORK_EXPORT Q_DECL_IMPORT
#endif

//依赖于同文件夹下的 mqttinc 中的mqtt 库头文件  不在项目中
class QMqttClient;
class QMqttTopicName;
//依赖common 中的数据结构 ParameterData
class ParameterData;
class OM_NETWORK_EXPORT MqttNetworkClicnt : public QObject
{
    Q_OBJECT
public:
    explicit  MqttNetworkClicnt();
    explicit  MqttNetworkClicnt(const ParameterData& config);
    ~MqttNetworkClicnt();
    bool startClient(const ParameterData& config);
    bool publishMessage(const ParameterData& message);
    bool subscribeMessage(const ParameterData& message);
private slots:
    void doConnected();
    void doMessageRecvied(const QByteArray &message, const QMqttTopicName &topic);
    void updateStateChange();
private:
    void initConnects();
private:
    QMqttClient *m_pClient = nullptr;
};

#endif // OM_NETWORK_MQTTNETWORKCLICNT_H
