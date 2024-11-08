#include "getdevicedata.h"

void GetDeviceData::run()
{
    using namespace std::chrono_literals;
    daq::ChannelPtr channel = instance.getDevices().getItemAt(deviceid).getChannels()[channelid];
    daq::SignalPtr signal = channel.getSignals()[signalid];
    daq::StreamReaderPtr reader = daq::StreamReader<double, uint64_t>(signal);
    // Get the resolution and origin
    daq::DataDescriptorPtr descriptor = signal.getDomainSignal().getDescriptor();
    daq::RatioPtr resolution = descriptor.getTickResolution();
    daq::StringPtr origin = descriptor.getOrigin();
    daq::StringPtr unitSymbol = descriptor.getUnit().getSymbol();
    double samples[1];
    uint64_t domainSamples[1];
    while (!stopRequested)
    {
        std::this_thread::sleep_for(16ms);
        daq::SizeT count = 1;
        reader.readWithDomain(samples, domainSamples, &count);
        if (count > 0)
        {
            daq::Float domainValue = (daq::Int) domainSamples[count - 1] * resolution;
            emit dataRead(threadid,samples[count - 1],domainValue);
        }
    }
}
/**
 * @brief GetDeviceData::stop   停止线程
 */
void GetDeviceData::stop()
{
    stopRequested=true;
}

