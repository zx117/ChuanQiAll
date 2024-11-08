#ifndef ChannelBuffer_H
#define ChannelBuffer_H

#include <QObject>

class ChannelBuffer : public QObject
{
    Q_OBJECT
public:
    explicit ChannelBuffer(quint32 channelID, QObject *parent = nullptr);
    ~ChannelBuffer();

    quint32 getChannelId() const;

    void setSampleRate(const double sr);
    double getSampleRate() const;

private:
    quint32 m_channelId;
    double m_sampleRate;
    std::string m_channelName;
};

#endif // ChannelBuffer_H
