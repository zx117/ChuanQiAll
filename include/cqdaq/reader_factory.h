
#pragma once
#include <cqdaq/stream_reader_ptr.h>
#include <cqdaq/block_reader_ptr.h>
#include <cqdaq/tail_reader_ptr.h>
#include <cqdaq/packet_reader_ptr.h>
#include <cqdaq/context_ptr.h>
#include <cqdaq/input_port_ptr.h>
#include <cqdaq/multi_reader_ptr.h>
#include <cqdaq/sample_type_traits.h>
#include <cqdaq/signal_ptr.h>
#include <cqdaq/input_port_config_ptr.h>
#include <cqdaq/reader_status_ptr.h>
#include <cqdaq/block_reader_status_ptr.h>
#include <cqdaq/multi_reader_builder_ptr.h>

BEGIN_NAMESPACE_CQDAQ

using UndefinedType = void;

inline ReaderStatusPtr ReaderStatus(const EventPacketPtr& packet = nullptr, Bool valid = true)
{
    return ReaderStatus_Create(packet, valid);
}

inline BlockReaderStatusPtr BlockReaderStatus(const EventPacketPtr& packet = nullptr, Bool valid = true, SizeT readSamples = 0)
{
    return BlockReaderStatus_Create(packet, valid, readSamples);
}

/*!
 * @brief Creates a reader that eases reading packets from the signal.
 * @param signal The signal to read the packets from.
 */
inline PacketReaderPtr PacketReader(SignalPtr cq_signal)
{
    return PacketReader_Create(cq_signal);
}

/*!
 * @brief Creates a reader that eases reading packets from the port.
 * @param input The input port to read the packets from.
 */
inline PacketReaderPtr PacketReaderFromPort(InputPortConfigPtr port)
{
    return PacketReaderFromPort_Create(port);
}

/*!
 * @brief Creates a signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads.
 * @param port The port to read the data from.
 * @param valueReadType The sample-type type to read signal values as. Implicitly convert from actual type to this one if conversion exists.
 * @param domainReadType The sample-type type to read signal domain as. Implicitly convert from actual type to this one if conversion exists.
 * @param timeoutType The type of time-out to use. See @see ReadTimeoutType.
 */
inline StreamReaderPtr StreamReaderFromPort(InputPortConfigPtr port,
                                    SampleType valueReadType,
                                    SampleType domainReadType,
                                    ReadMode mode = ReadMode::Scaled,
                                    ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return StreamReaderFromPort_Create(port, valueReadType, domainReadType, mode, timeoutType);
}

/*!
 * @brief Creates a signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads.
 * @param signal The signal to read the data from.
 * @param valueReadType The sample-type type to read signal values as. Implicitly convert from actual type to this one if conversion exists.
 * @param domainReadType The sample-type type to read signal domain as. Implicitly convert from actual type to this one if conversion exists.
 * @param timeoutType The type of time-out to use. See @see ReadTimeoutType.
 */
inline StreamReaderPtr StreamReader(SignalPtr cq_signal,
                                    SampleType valueReadType,
                                    SampleType domainReadType,
                                    ReadMode mode = ReadMode::Scaled,
                                    ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return StreamReader_Create(cq_signal, valueReadType, domainReadType, mode, timeoutType);
}

/*!
 * @brief Creates a signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads.
 * @param signal The signal to read the data from.
 * @param timeoutType The type of time-out to use. See @see ReadTimeoutType.
 * @tparam TValueType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @tparam TDomainType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
template <typename TValueType = double, typename TDomainType = ClockTick>
StreamReaderPtr StreamReader(SignalPtr cq_signal, ReadMode mode, ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return StreamReader(
        cq_signal,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType,
        mode,
        timeoutType
    );
}

/*!
 * @brief Creates a signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads.
 * @param signal The signal to read the data from.
 * @param timeoutType The type of time-out to use. See @see ReadTimeoutType.
 * @tparam TValueType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @tparam TDomainType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
template <typename TValueType = double, typename TDomainType = ClockTick>
StreamReaderPtr StreamReader(SignalPtr cq_signal, ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return StreamReader(
        cq_signal,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType,
        ReadMode::Scaled,
        timeoutType
    );
}

/*!
 * @brief Creates a signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads.
 * @param signal The signal to read the data from.
 * @param timeoutType The type of time-out to use. See @see ReadTimeoutType.
 */
inline StreamReaderPtr StreamReader(SignalPtr cq_signal, ReadMode mode = ReadMode::Scaled, ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return StreamReader<>(cq_signal, mode, timeoutType);
}

/*!
 * @brief Creates a new reader using the data of the existing one.
 * Used when a StreamReader gets invalidated because of incompatible change in signal descriptor.
 * This will reuse all of the read and connection info so no data is lost when changing to the new reader type.
 * @param invalidatedReader The reader from which to steal the read and connection info. If the passed-in
 * reader is not invalidated it will be invalidated after the call.
 * @param valueReadType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @param domainReadType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
inline StreamReaderPtr StreamReaderFromExisting(StreamReaderPtr invalidatedReader, SampleType valueReadType, SampleType domainReadType)
{
    return StreamReaderFromExisting_Create(invalidatedReader, valueReadType, domainReadType);
}

/*!
 * @brief Creates a new reader using the data of the existing one.
 * Used when a StreamReader gets invalidated because of incompatible change in signal descriptor.
 * This will reuse all of the read and connection info so no data is lost when changing to the new reader type.
 * @param invalidatedReader The reader from which to steal the read and connection info. If the passed-in
 * reader is not invalidated it will be invalidated after the call.
 * @tparam TValueType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @tparam TDomainType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
template <typename TValueType = double, typename TDomainType = ClockTick>
StreamReaderPtr StreamReaderFromExisting(StreamReaderPtr invalidatedReader)
{
    return StreamReaderFromExisting(
        invalidatedReader,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType
    );
}

/*!
 * @brief A reader that only ever reads the last N samples, subsequent calls may result in overlapping data.
 * @param signal The signal to read the data from.
 * @param historySize The maximum amount of samples in history to keep.
 * @param valueReadType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @param domainReadType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
inline TailReaderPtr TailReader(SignalPtr cq_signal,
                                SizeT historySize,
                                SampleType valueReadType,
                                SampleType domainReadType,
                                ReadMode mode = ReadMode::Scaled)
{
    return TailReader_Create(cq_signal, historySize, valueReadType, domainReadType, mode);
}
/*!
 * @brief A reader that only ever reads the last N samples, subsequent calls may result in overlapping data.
 * @param port The port to read the data from.
 * @param historySize The maximum amount of samples in history to keep.
 * @param valueReadType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @param domainReadType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
inline TailReaderPtr TailReaderFromPort(InputPortConfigPtr port,
                                        SizeT historySize,
                                        SampleType valueReadType,
                                        SampleType domainReadType,
                                        ReadMode mode = ReadMode::Scaled)
{
    return TailReaderFromPort_Create(port, historySize, valueReadType, domainReadType, mode);
}


/*!
 * @brief A reader that only ever reads the last N samples, subsequent calls may result in overlapping data.
 * @param signal The signal to read the data from.
 * @param historySize The maximum amount of samples in history to keep.
 * @tparam TValueType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @tparam TDomainType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
template <typename TValueType = double, typename TDomainType = ClockTick>
TailReaderPtr TailReader(SignalPtr cq_signal, SizeT historySize, ReadMode mode = ReadMode::Scaled)
{
    return TailReader(
        cq_signal,
        historySize,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType,
        mode
    );
}

/*!
 * @brief A reader that only ever reads the last N samples, subsequent calls may result in overlapping data.
 * @param signal The signal to read the data from.
 * @param historySize The maximum amount of samples in history to keep.
 */
inline TailReaderPtr TailReader(SignalPtr cq_signal, SizeT historySize, ReadMode mode = ReadMode::Scaled)
{
    return TailReader<>(std::move(cq_signal), historySize, mode);
}

/*!
 * @brief Creates a new reader using the data of the existing one.
 * Used when a TailReader gets invalidated because of incompatible change in the signal descriptor.
 * This will reuse all of the read and connection info so no data is lost when changing to the new reader type.
 * @param invalidatedReader The reader from which to steal the read and connection info. If the passed-in
 * reader is not invalidated it will be invalidated after the call.
 * @param historySize The maximum amount of samples in history to keep.
 * @param valueReadType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @param domainReadType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
inline TailReaderPtr TailReaderFromExisting(TailReaderPtr invalidatedReader, SizeT historySize, SampleType valueReadType, SampleType domainReadType)
{
    return TailReaderFromExisting_Create(invalidatedReader, historySize, valueReadType, domainReadType);
}

/*!
 * @brief Creates a new reader using the data of the existing one.
 * Used when a TailReader gets invalidated because of incompatible change in the signal descriptor.
 * This will reuse all of the read and connection info so no data is lost when changing to the new reader type.
 * @param invalidatedReader The reader from which to steal the read and connection info. If the passed-in
 * reader is not invalidated it will be invalidated after the call.
 * @param historySize The maximum amount of samples in history to keep.
 * @tparam TValueType The sample-type type to read signal values as. Implicitly convert from actual type to
 * this one if conversion exists.
 * @tparam TDomainType The sample-type type to read signal domain as. Implicitly convert from actual type to
 * this one if conversion exists.
 */
template <typename TValueType = double, typename TDomainType = ClockTick>
StreamReaderPtr TailReaderFromExisting(TailReaderPtr invalidatedReader, SizeT historySize)
{
    return TailReaderFromExisting(
        invalidatedReader,
        historySize,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType
    );
}

inline BlockReaderPtr BlockReader(SignalPtr cq_signal,
                                  SizeT blockSize,
                                  SampleType valueReadType,
                                  SampleType domainReadType,
                                  ReadMode mode = ReadMode::Scaled)
{
    return BlockReader_Create(cq_signal, blockSize, valueReadType, domainReadType, mode);
}

inline BlockReaderPtr BlockReaderFromPort(InputPortConfigPtr port,
                                  SizeT blockSize,
                                  SampleType valueReadType,
                                  SampleType domainReadType,
                                  ReadMode mode = ReadMode::Scaled)
{
    return BlockReaderFromPort_Create(port, blockSize, valueReadType, domainReadType, mode);
}

inline BlockReaderPtr BlockReaderFromExisting(const BlockReaderPtr& invalidatedReader,
                                              SizeT blockSize,
                                              SampleType valueReadType,
                                              SampleType domainReadType)
{
    return BlockReaderFromExisting_Create(invalidatedReader, valueReadType, domainReadType, blockSize);
}

template <typename TValueType = double, typename TDomainType = ClockTick>
BlockReaderPtr BlockReader(SignalPtr cq_signal, SizeT blockSize, ReadMode mode = ReadMode::Scaled)
{
    return BlockReader(
        cq_signal,
        blockSize,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType,
        mode
    );
}

template <typename TValueType = double, typename TDomainType = ClockTick>
BlockReaderPtr BlockReaderFromPort(InputPortConfigPtr port, SizeT blockSize, ReadMode mode = ReadMode::Scaled)
{
    return BlockReaderFromPort(
        port,
        blockSize,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType,
        mode
    );
}


template <typename TValueType = double, typename TDomainType = ClockTick>
BlockReaderPtr BlockReaderFromExisting(BlockReaderPtr invalidatedReader, SizeT blockSize)
{
    return BlockReaderFromExisting(
        invalidatedReader,
        blockSize,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType
    );
}

inline MultiReaderBuilderPtr MultiReaderBuilder()
{
    return MultiReaderBuilder_Create();
}

inline MultiReaderPtr MultiReaderFromBuilder(const MultiReaderBuilderPtr& builder)
{
    return MultiReaderFromBuilder_Create(builder);
}

inline MultiReaderPtr MultiReader(const ListPtr<ISignal>& cq_signals,
                                  SampleType valueReadType,
                                  SampleType domainReadType,
                                  ReadMode mode = ReadMode::Scaled,  
                                  ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return MultiReader_Create(cq_signals, valueReadType, domainReadType, mode, timeoutType);
}

inline MultiReaderPtr MultiReaderFromPort(ListPtr<IInputPortConfig> ports,
                                  SampleType valueReadType,
                                  SampleType domainReadType,
                                  ReadMode mode = ReadMode::Scaled,  
                                  ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return MultiReader_Create(ports, valueReadType, domainReadType, mode, timeoutType);
}

inline MultiReaderPtr MultiReaderEx(const ListPtr<ISignal>& cq_signals,
                                    SampleType valueReadType,
                                    SampleType domainReadType,
                                    ReadMode mode = ReadMode::Scaled,
                                    ReadTimeoutType timeoutType = ReadTimeoutType::All,
                                    Int requiredCommonSampleRate = -1,
                                    bool startOnFullUnitOfDomain = false)
{
    return MultiReaderEx_Create(cq_signals, valueReadType, domainReadType, mode, timeoutType, requiredCommonSampleRate, startOnFullUnitOfDomain);
}

inline MultiReaderPtr MultiReaderFromExisting(const MultiReaderPtr& invalidatedReader, SampleType valueReadType, SampleType domainReadType)
{
    return MultiReaderFromExisting_Create(invalidatedReader, valueReadType, domainReadType);
}

template <typename TValueType = double, typename TDomainType = ClockTick>
MultiReaderPtr MultiReader(ListPtr<ISignal> cq_signals, ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return MultiReader(
        cq_signals,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType,
        ReadMode::Scaled,
        timeoutType
    );
}
template <typename TValueType = double, typename TDomainType = ClockTick>
inline MultiReaderPtr MultiReaderFromPort(ListPtr<IInputPortConfig> ports,
                                  ReadMode mode = ReadMode::Scaled,  
                                  ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return MultiReader_Create(ports, SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType, mode, timeoutType);
}

template <typename TValueType = double, typename TDomainType = ClockTick>
MultiReaderPtr MultiReaderEx(ListPtr<ISignal> cq_signals, ReadTimeoutType timeoutType = ReadTimeoutType::All, Int requiredCommonSampleRate = -1, bool startOnFullUnitOfDomain = false)
{
    return MultiReaderEx(cq_signals,
                         SampleTypeFromType<TValueType>::SampleType,
                         SampleTypeFromType<TDomainType>::SampleType,
                         ReadMode::Scaled,
                         timeoutType,
                         requiredCommonSampleRate,
                         startOnFullUnitOfDomain);
}

template <typename TValueType = double, typename TDomainType = ClockTick>
MultiReaderPtr MultiReader(ListPtr<ISignal> cq_signals, ReadMode mode, ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return MultiReader(
        cq_signals,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType,
        mode,
        timeoutType
    );
}

template <typename TDomainType = ClockTick>
MultiReaderPtr MultiReaderRaw(ListPtr<ISignal> cq_signals, ReadTimeoutType timeoutType = ReadTimeoutType::All)
{
    return MultiReader(
        cq_signals,
        SampleType::Undefined,
        SampleTypeFromType<TDomainType>::SampleType,
        ReadMode::RawValue,
        timeoutType
    );
}

template <typename TValueType = double, typename TDomainType = ClockTick>
MultiReaderPtr MultiReaderFromExisting(MultiReaderPtr invalidatedReader)
{
    return MultiReaderFromExisting(
        invalidatedReader,
        SampleTypeFromType<TValueType>::SampleType,
        SampleTypeFromType<TDomainType>::SampleType
    );
}


END_NAMESPACE_CQDAQ
