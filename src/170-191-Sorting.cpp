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

template <typename T> void insertion_sort(std::vector<T> &v)
{
    // For index k in v where start <= k <= end, copy v[k] to v[k+1]
    // value of v[start] is undefined.
    auto shift_right = [&v](int32_t start, int32_t end)
    {
        for (int32_t i = end; i >= start; i--)
        {
            v[i + 1] = v[i];
        }
    };

    for (size_t n = 0; n < v.size(); n++)
    {
        for (size_t k = 0; k < n; k++)
        {
            if (v[k] > v[n])
            {
                uint32_t tmp = v[n];
                shift_right(k, n-1);
                v[k] = tmp;
            }
        }
    }
}

// template instantiation
template void bubble_sort<uint32_t>(std::vector<uint32_t> &v);
template void selection_sort<uint32_t>(std::vector<uint32_t> &v);
template void insertion_sort<uint32_t>(std::vector<uint32_t> &v);

} // namespace sorting
