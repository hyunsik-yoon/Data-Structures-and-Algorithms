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

        uint32_t ind = _v.size() - 1;

        while (compare_to_parent(ind))
        {
            ind = swap_with_parent(ind);
        }
    };

    bool is_empty() { return _v.size() == 0; }

    bool exist(uint32_t ind) { return ind < _v.size(); }

    T remove_top()
    {
        assert(not is_empty());

        T root_val = _v[0];

        _v[0] = _v[_v.size() - 1]; // relace root with last node
        _v.resize(_v.size() - 1);

        uint32_t root_ind = 0;

        while (true)
        {
            T l_ch_ind = root_ind * 2 + 1;  // index of left child
            T r_ch_ind = l_ch_ind + 1;      // index of right child

            if (exist(r_ch_ind)) // when both left and right subtree exist
            {
                if (_v[r_ch_ind] > _v[l_ch_ind])
                {
                    if (_v[r_ch_ind] > _v[root_ind])
                    {
                        swap_with_parent(r_ch_ind);
                        root_ind = r_ch_ind;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (_v[l_ch_ind] > _v[root_ind])
                    {
                        swap_with_parent(l_ch_ind);
                        root_ind = l_ch_ind;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (exist(l_ch_ind)) // when only left subtree exists
            {
                if (_v[l_ch_ind] > _v[root_ind])
                {
                    swap_with_parent(l_ch_ind);
                    root_ind = l_ch_ind;
                }
                else
                {
                    break;
                }
            }
            else // no subtree exist
            {
                break;
            }
        }
        return root_val;
    }

    const std::vector<T> &as_vector() { return _v; }

protected:
    uint32_t parent_index(uint32_t child_ind)
    {
        assert(child_ind != 0);

        return (child_ind - 1) / 2;
    }

    bool compare_to_parent(uint32_t child_ind)
    {
        if (child_ind == 0)
        {
            return false;
        }

        uint32_t parent_ind = parent_index(child_ind);

        return (_v[child_ind] > _v[parent_ind]);
    }

    // swap child and parent and returns new index (which was parent index)
    uint32_t swap_with_parent(uint32_t child_ind)
    {
        assert(child_ind != 0);

        uint32_t parent_ind = parent_index(child_ind);

        auto parent_temp = _v[parent_ind];
        _v[parent_ind] = _v[child_ind];
        _v[child_ind] = parent_temp;

        return parent_ind;
    }

private:
    std::vector<T> _v;
};

// TODO
// Write class for
// template <typename T> class BinaryHeap<BHType::MIN, T>

} // __139__BINARY_HEAP__

#endif
