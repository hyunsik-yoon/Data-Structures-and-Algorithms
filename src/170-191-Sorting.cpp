#include "170-191-Sorting.h"

#include <cassert>
#include <stdexcept>
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

} // namespace sorting


// For merge Sort
namespace
{

template <typename T> const std::vector<T> merge(const std::vector<T> &left, const std::vector<T> &right)
{
    uint32_t v_size = left.size() + right.size();
    std::vector<T> vec(v_size);

    uint32_t l = 0;  // for index of left vector
    uint32_t r = 0;  // for index of right vector
    uint32_t v = 0;  // for index of returned vector

    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            vec[v] = left[l];
            l++;
            v++;
        }
        else
        {
            vec[v] = right[r];
            r++;
            v++;
        }
    }

    // copy leftover from left to the end of vec
    std::copy(left.begin() + l, left.end(), vec.begin() + v);
    uint32_t l_copied_count = left.size() - l;

    // copy leftover from right to the end of vec
    std::copy(right.begin() + r, right.end(), vec.begin() + v + l_copied_count);

    return vec;
}

} // namespace

namespace sorting
{

template <typename T> const std::vector<T> merge_sort(const std::vector<T> &v)
{
    if (v.size() <= 1)
    {
        return v;
    }

    int32_t mid_idx = v.size() / 2;
    //   Example
    //       size()        mid_idx
    //          4            2
    //          5            2

    const auto left_v = merge_sort(std::vector<T>{v.begin(), v.begin() + mid_idx});
    const auto right_v = merge_sort(std::vector<T>{v.begin() + mid_idx, v.end()});

    return merge(left_v, right_v);
}

} // namespace sorting

// For quick sort
// This implementation follows figure at 1:05 in chapter 182, where pivot is initially set to the leftmost element.
namespace
{

// Partition values in v of range (start: inclusive index, end: exclusive index)
template <typename T> int32_t partition(std::vector<T> &v, int32_t start, int32_t end)
{
    assert(start < end);

    int32_t pivot = end - 1;

    for (int32_t k = start; k < pivot; )
    {
        if (v[k] > v[pivot])
        {
            // Note: this works when start - end == 2
            // when v[k] == 7 and v[pivot] == 3
            auto pivot_val = v[pivot];  // 7(k) 2 4 3(pivot)
            v[pivot] = v[k];            // 7    2 4 7
            v[k] = v[pivot - 1];        // 4    2 4 7
            v[pivot - 1] = pivot_val;   // 4    2 3 7

            pivot = pivot - 1;
            // let's not increase k
        }
        else
        {
            k++;
        }
    }

    return pivot;
}

// Perform quick sort for a vector (start: inclusive index, end: exclusive index)
template <typename T> void quick_sort(std::vector<T> &v, int32_t start, int32_t end)
{
    if (end - start <= 1)
    {
        return;
    }

    auto pivot = partition(v, start, end);

    quick_sort(v, start, pivot);
    quick_sort(v, pivot + 1, end);
}

} // namespace

namespace sorting
{

template <typename T> void quick_sort(std::vector<T> &v)
{
    ::quick_sort(v, 0, v.size());
}

} // namespace sorting

// template instantiation
namespace sorting
{

template void bubble_sort<uint32_t>(std::vector<uint32_t> &v);
template void selection_sort<uint32_t>(std::vector<uint32_t> &v);
template void insertion_sort<uint32_t>(std::vector<uint32_t> &v);
template const std::vector<uint32_t> merge_sort(const std::vector<uint32_t> &v);
template void quick_sort<uint32_t>(std::vector<uint32_t> &v);

} // namespace sorting
