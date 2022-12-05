#ifndef __122__QUEUE_WITH_LINKED_LIST__
#define __122__QUEUE_WITH_LINKED_LIST__

#include "LinkedList.h"

#include <cassert>

namespace n122
{

template <typename T>
class Queue
{
public:
    Queue() {  }

    void queue(const T &item)
    {
        _l.append(item);
    }

    const T dequeue()
    {
        assert(not is_empty());

        return _l.remove_head();
    }

    bool is_empty()
    {
        return _l.is_empty();
    }

private:
    ds::LinkedList<int> _l;
};

} // namespace n122


#endif //  __122__QUEUE_WITH_LINKED_LIST__
