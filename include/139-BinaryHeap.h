#ifndef __139__BINARY_HEAP__
#define __139__BINARY_HEAP__

#include <cassert>
#include <stdexcept>
#include <vector>

namespace n139
{

enum class BHType
{
    MIN, MAX
};

template <BHType BHT, typename T> class BinaryHeap;

template <typename T> class BinaryHeap<BHType::MAX, T>
{
public:
    BinaryHeap() = default;

    void insert(const T val)
    {
        _v.emplace_back(val);

        int32_t ind = _v.size() - 1;

        while (compare_to_parent(ind))
        {
            ind = swap_with_parent(ind);
        }
    };

    const std::vector<T> &as_vector() { return _v; }

protected:
    int32_t parent_index(int32_t child_ind)
    {
        assert(child_ind != 0);

        return (child_ind - 1) / 2;
    }

    bool compare_to_parent(int32_t child_ind)
    {
        if (child_ind == 0)
        {
            return false;
        }

        int32_t parent_ind = parent_index(child_ind);

        return (_v[child_ind] > _v[parent_ind]);
    }

    // swap child and parent and returns new index (which was parent index)
    int32_t swap_with_parent(int32_t child_ind)
    {
        assert(child_ind != 0);

        int32_t parent_ind = parent_index(child_ind);

        auto parent_temp = _v[parent_ind];
        _v[parent_ind] = _v[child_ind];
        _v[child_ind] = parent_temp;

        return parent_ind;
    }

private:
    std::vector<T> _v;
};


} // __139__BINARY_HEAP__

#endif
