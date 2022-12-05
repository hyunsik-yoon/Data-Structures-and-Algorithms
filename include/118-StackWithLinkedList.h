#ifndef __118__STACK_WITH_LINKED_LIST__
#define __118__STACK_WITH_LINKED_LIST__

#include "LinkedList.h"

namespace n118
{

template <typename T>
class Stack
{
public:
    void push(const T &item)
    {
        _l.insert_head(item);
    }

    const T pop()
    {
        assert(not is_empty());

        return _l.remove_head();
    }

    bool is_empty()
    {
        return _l.is_empty();
    }

private:
    ds::LinkedList<T> _l;
    
};

} // namespace n118


#endif // __118__STACK_WITH_LINKED_LIST__
