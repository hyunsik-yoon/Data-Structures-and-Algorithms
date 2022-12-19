#ifndef __122__QUEUE__
#define __122__QUEUE__

#include "LinkedList.h"

#include <cassert>
#include <vector>

namespace n122
{

enum class DS
{
    LinkedList, Array
};


template <typename T, DS DST> class Queue;

/**
 * Queue using Linked List
 */
template <typename T> class Queue<T, DS::LinkedList>
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
    ds::LinkedList<T> _l;
};

/**
 * Queue using Array
 */

template <typename T> class CircularVector
{
public:
    CircularVector(uint32_t size): _head(-1), _tail(-1), _size(size) { _v.resize(_size); }

    void append(const T& val)
    {
        if (_tail == -1)
        {
            _head = _tail = 0;
            _v[_tail] = val;
        }
        else
        {
            ++_tail;
            _tail = _tail % _size;
            if (_tail == _head)
            {
                throw std::runtime_error("Overflow");
            }

            _v[_tail] = val;
        }
    }

    const T remove_head()
    {
        assert(not is_empty());

        if (_head == _tail)
        {
            // only one item
            auto val = _v[_head];
            _head = _tail = -1;
            return val;
        }
        else
        {
            auto val = _v[_head];
            ++_head;
            _head = _head % _size;
            return val;
        }
    }

    bool is_empty() { return (_head == _tail) && (_head == -1); }

    // TODO implement resize()

private:
    int32_t _head, _tail;
    uint32_t _size;

    std::vector<T> _v;
};

template <typename T> class Queue<T, DS::Array>
{
public:
    Queue(uint32_t size): _v(size) { /* empty */ }

    void queue(const T &item)
    {
        _v.append(item);
    }

    const T dequeue()
    {
        assert(not is_empty());

        return _v.remove_head();
    }

    bool is_empty()
    {
        return _v.is_empty();
    }

private:
    CircularVector<T> _v;
};

} // namespace n122


#endif //  __122__QUEUE__
