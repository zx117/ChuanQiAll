#pragma once

#include "fw_block_iterator.h"
#include "uni_assert.h"
#include "uni_defines.h"

#include <cstddef>
#include <limits>
#include <vector>

namespace cq
{
namespace framework
{
    class IfIteratorUpdater;

    class StreamIterator
    {
    public:
        StreamIterator() noexcept;

        /// Start address of the sample
        CQ_NODISCARD inline const void* data() const noexcept
        {
            return valid() ? m_current_iterator.data() : nullptr;
        }

        /// Timestamp of the sample
        CQ_NODISCARD inline std::uint64_t timestamp() const noexcept
        {
            return valid() ? m_current_iterator.timestamp() : 0;
        }

        CQ_NODISCARD inline std::size_t size() const noexcept
        {
            return valid() ? m_current_iterator.size() : 0;
        }

        template<class SampleFormat>
        CQ_NODISCARD inline SampleFormat value() const noexcept
        {
            if (const void* data_ptr = data())
            {
                return *static_cast<const SampleFormat*>(data_ptr);
            }
            return std::numeric_limits<SampleFormat>::quiet_NaN();
        }

        CQ_NODISCARD inline bool valid() const noexcept
        {
            return m_block_index >= 0;
        }

        void addRange(const BlockIterator& begin, const BlockIterator& end);

        void clearRanges() noexcept;

        void setDataRequester(IfIteratorUpdater* requester) noexcept;

        inline StreamIterator& operator++()
        {
            CQ_ASSERT(valid());
            ++m_current_iterator;
            if (m_current_iterator == m_blocks_ranges[m_block_index].second)
            {
                getNextBlock();
            }
            return *this;
        }

        inline StreamIterator& operator--()
        {
            CQ_ASSERT(valid());
            if (m_current_iterator == m_blocks_ranges[m_block_index].first)
            {
                getPreviousBlock();
            }
            --m_current_iterator;
            return *this;
        }


        CQ_NODISCARD inline bool operator==(const StreamIterator& other) const noexcept
        {
            return m_current_iterator == other.m_current_iterator;
        };

        CQ_NODISCARD inline bool operator!=(const StreamIterator& other) const noexcept
        {
            return !(*this == other);
        }

        void setSignalGaps(bool enabled) noexcept;
        void setSkipGaps(bool enabled);

        CQ_NODISCARD std::uint64_t getTotalSampleCount() const noexcept;

        using BlockIteratorRange = std::pair<BlockIterator, BlockIterator>;

    private:
        void getNextBlock();
        void getPreviousBlock();

    private:
        std::vector<BlockIteratorRange> m_blocks_ranges;
        int m_block_index;
        BlockIterator m_current_iterator;
        IfIteratorUpdater* m_data_requester;
        bool m_signal_gaps;
        bool m_skip_gaps;
    };

    class IfIteratorUpdater
    {
    public:
        virtual void updateStreamIterator(StreamIterator* iterator) = 0;
        virtual ~IfIteratorUpdater() = default;
    };

}

}