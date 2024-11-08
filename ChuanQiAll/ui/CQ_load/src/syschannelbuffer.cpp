#include "syschannelbuffer.h"

ChannelBuffer::ChannelBuffer(quint32 channelID, QObject *parent) : QObject(parent),
    m_channelId(0),
    m_sampleRate(1)
{}

ChannelBuffer::~ChannelBuffer()
{}

quint32 ChannelBuffer::getChannelId() const
{
    return m_channelId;
}

void ChannelBuffer::setSampleRate(const double rate)
{
   if(qAbs(m_sampleRate - rate) < 1e3){
        m_sampleRate = rate;
    }
}

double ChannelBuffer::getSampleRate() const
{
    return m_sampleRate;
}
