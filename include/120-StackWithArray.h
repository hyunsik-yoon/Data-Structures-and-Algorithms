#ifndef __120__STACK_WITH_ARRAY__
#define __120__STACK_WITH_ARRAY__

#include <cassert>
#include <vector>
#include <stdexcept>
#include <stdint.h>

namespace n120
{

template <typename T>
class Stack
{
public:
    Stack() : _tail(-1), _size(16) { _v.resize(_size); }

    void push(const T &item)
    {
        _tail++;
        if (_tail == _size)
        {
            throw std::runtime_error("Stack overflow");
        }

        _v[_tail] = item;
    }

    const T pop()
    {
        assert(not is_empty());

        return _v[_tail--];
    }

    bool is_empty()
    {
        return (_tail == -1);
    }

    void resize(int32_t size)
    {
        // This does not guarantee data corruption due to shrinking stack size
        _size = size;
        _v.resize(_size);
    }

private:
    std::vector<T> _v;

    int32_t _tail; // Empty when _tail == -1
    int32_t _size;    
};

} // namespace n120


#endif // __120__STACK_WITH_ARRAY__
