#include "73-MergeSortedArrays.h"

#include <iostream>

namespace 
{
    void append(std::vector<int> &dest, uint32_t dest_idx, const std::vector<int> &src, uint32_t src_idx)
    {
        for (uint32_t i = src_idx; i < src.size(); i++, dest_idx++)
        {
            dest[dest_idx] = src[i];
        }
    }
}

const std::vector<int> merge_sorted_arrays(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> c(a.size() + b.size());

    uint32_t a_idx = 0, b_idx = 0, c_idx = 0;
    while (true)
    {
        if (a_idx == a.size())
        {
            append(c, c_idx, b, b_idx);
            break;
        }
        else if (b_idx == b.size())
        {
            append(c, c_idx, a, a_idx);
            break;
        }

        if (a[a_idx] < b[b_idx])
        {
            c[c_idx++] = a[a_idx++];
        }
        else if (b[b_idx] < a[a_idx])
        {
            c[c_idx++] = b[b_idx++];
        }
        else // same
        {
            c[c_idx++] = a[a_idx++];
            c[c_idx++] = b[b_idx++];
        }
    }

    return c;
}
