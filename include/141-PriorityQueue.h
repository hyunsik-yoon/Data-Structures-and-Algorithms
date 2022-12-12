#ifndef __141__PROPROTY_QUEUE__
#define __141__PROPROTY_QUEUE__

#include "139-BinaryHeap.h"

#include <cassert>

namespace n141
{

using namespace n139;

template <typename T> class PriorityQueue : private BinaryHeap<BHType::MAX, T>
{
public:
    void queue(T val) { this->insert(val); }

    T dequeue()
    {
        // NOTE
        // Why do we need "this->" ?
        // Refer to https://stackoverflow.com/a/39667832
        assert(not this->is_empty());

        return this->remove_top();
    }
};

} // namespace n141

#endif // __141__PROPROTY_QUEUE__
