#include "132-BinarySearchTree.h"

#include <gtest/gtest.h>
#include <algorithm>

namespace debug
{
using namespace n132;

template <typename T>
inline void dump_dfs(Node<T> *root, std::vector<T> &v, T nullptr_marker)
{
    v.emplace_back(root->val());

    if (root->left())
    {
        dump_dfs(root->left(), v, nullptr_marker);
    }
    else
    {
        v.emplace_back(nullptr_marker);
    }

    if (root->right())
    {
        dump_dfs(root->right(), v, nullptr_marker);
    }
    else
    {
        v.emplace_back(nullptr_marker);
    }
};

template <typename T>
inline std::vector<T> dump(BinarySearchTree<T> &bst, T nullptr_marker)
{
    std::vector<T> v;
    if (bst.is_empty())
    {
        v.emplace_back(nullptr_marker);
    }
    else
    {
        dump_dfs(bst.root(), v, nullptr_marker);
    }
    return v;
}

} // namespace debug

TEST(binary_search_tree, empty)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    ASSERT_EQ(bst.is_empty(), true);
}

TEST(binary_search_tree, insert_1)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    int N =  -1; // nullptr_marker
    {
        bst.insert(100);

        ASSERT_EQ(bst.is_empty(), false);
        auto actual = debug::dump(bst, N);

        std::vector<int> expected = {
              100,
             N, N
        };
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
    }
    {
        bst.insert(50);

        auto actual = debug::dump(bst, N);

        std::vector<int> expected = {
               100,
             50,
            N, N,
                   N
        };
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
    }
    {
        bst.insert(180);

        auto actual = debug::dump(bst, N);

        std::vector<int> expected = {
               100,
             50,
            N, N,
                   180,
                  N,  N
        };
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
    }
}
