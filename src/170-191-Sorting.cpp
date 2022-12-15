#include "170-191-Sorting.h"

#include <stdint.h>

namespace
{

template <typename T> void swap(T &a, T &b)
{
    auto temp = a;
    a = b;
    b = temp;
}

} // namespace


namespace sorting
{

template <typename T> void bubble_sort(std::vector<T> &v)
{
    for (size_t last = v.size() - 1; last > 0; last--)
    {
        for (size_t x = 0; x <= last - 1; x++)
        {
            if (v[x] > v[x + 1])
            {
                swap(v[x], v[x + 1]);
            }
        }
    }
}

template <typename T> void selection_sort(std::vector<T> &v)
{
    for (size_t start = 0; start < v.size(); start++)
    {
        T min_idx = start;
        for (size_t n = start + 1; n < v.size(); n++)
        {
            if (v[n] < v[min_idx])
            {
                min_idx = n;
            }
        }
        swap(v[start], v[min_idx]);
    }
}

// template instantiation
template void bubble_sort<uint32_t>(std::vector<uint32_t> &v);
template void selection_sort<uint32_t>(std::vector<uint32_t> &v);

} // namespace sorting
