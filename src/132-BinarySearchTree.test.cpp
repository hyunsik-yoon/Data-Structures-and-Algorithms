#include "132-BinarySearchTree.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>

namespace debug
{
using namespace n132;

template <typename T>
bool is_valid(Node<T> *r)
{
    if (r == nullptr)
    {
        return true;
    }

    if (r->left() != nullptr)
    {
        if (not (r->val() > r->left()->val()))
        {
            return false;
        }
    }

    if (r->right() != nullptr)
    {
        if (not (r->val() < r->right()->val()))
        {
            return false;
        }
    }

    return is_valid(r->left()) && is_valid(r->right());
}

template <typename T>
bool is_valid(BinarySearchTree<T> &bst)
{
    return is_valid(bst.root());
}

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

TEST(binary_search_tree, insert_lookup_1)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    ASSERT_FALSE(bst.lookup(100));

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

        ASSERT_TRUE(bst.lookup(100) != nullptr);
        ASSERT_TRUE(bst.lookup(12345) == nullptr);
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

        ASSERT_TRUE(bst.lookup(50) != nullptr);
        ASSERT_TRUE(bst.lookup(100) != nullptr);
        ASSERT_TRUE(bst.lookup(12345) == nullptr);
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

        ASSERT_TRUE(bst.lookup(180) != nullptr);
        ASSERT_TRUE(bst.lookup(12345) == nullptr);
    }
    {
        bst.insert(75);

        auto actual = debug::dump(bst, N);

        std::vector<int> expected = {
               100,
            50,
          N,  75,
             N, N,
                    180,
                   N,  N
        };
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));

        ASSERT_TRUE(bst.lookup(50) != nullptr);
        ASSERT_TRUE(bst.lookup(75) != nullptr);
        ASSERT_TRUE(bst.lookup(100) != nullptr);
        ASSERT_TRUE(bst.lookup(180) != nullptr);
        ASSERT_TRUE(bst.lookup(12345) == nullptr);
    }
}

TEST(binary_search_tree, lookup_2)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    //     100
    //   50   150
    // 20
    bst.insert(100);
    bst.insert(50);
    bst.insert(150);
    bst.insert(20);

    Node<int> **pr = nullptr;
    Node<int> *r = bst.lookup(20, pr);

    *pr = nullptr; // left node of val 150 is not nullptr
    delete r;  // remove node of val 20

    // now bst is
    //     100
    //   50   150

    int N =  -1; // nullptr_marker
    auto actual = debug::dump(bst, N);

    std::vector<int> expected = {
            100,
         50,
        N,  N,
                150,
                N,  N
    };
    ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
}

TEST(binary_search_tree, remove_against_empty_tree)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    ASSERT_EQ(bst.remove(12345), false);
}

TEST(binary_search_tree, remove_root_only_tree)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    bst.insert(100);

    ASSERT_EQ(bst.remove(100), true);
    ASSERT_EQ(bst.is_empty(), true);
}

TEST(binary_search_tree, remove_root_in_left_only_tree)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    bst.insert(100);  // this will be removed
    bst.insert(50);
    bst.insert(70); // this will be a new node

    ASSERT_EQ(bst.remove(100), true);

    int N =  -1; // nullptr_marker
    auto actual = debug::dump(bst, N);

    std::vector<int> expected = {
             70,
         50,
        N,  N,
                 N
    };
    ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
}

TEST(binary_search_tree, remove_root_in_complex_tree)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    /*           100
        50                  200
                        150     250
    */

    bst.insert(100);    // will be removed
    bst.insert(50);
    bst.insert(200);
    bst.insert(150);    // this will be a new root
    bst.insert(250);

    ASSERT_EQ(bst.remove(100), true);

    int N =  -1; // nullptr_marker
    auto actual = debug::dump(bst, N);

    std::vector<int> expected = {
             150,
         50,
        N,  N,
                   200,
                 N,   250,
                     N,  N
    };
    ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
}

TEST(binary_search_tree, remove_node_with_left_only_tree)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    /*          200
           100
        50
    */
    bst.insert(200);
    bst.insert(100);  // this will be removed
    bst.insert(50); // this will replace 100

    ASSERT_EQ(bst.remove(100), true);

    int N =  -1; // nullptr_marker
    auto actual = debug::dump(bst, N);

    std::vector<int> expected = {
              200,
         50,
        N,  N,
                    N
    };
    ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
}

TEST(binary_search_tree, remove_node_in_complex_tree)
{
    using namespace n132;
    BinarySearchTree<int> bst;

    /*           100
        50                  200
                        150     250
    */

    bst.insert(100);
    bst.insert(50);
    bst.insert(200);    // this will be removed
    bst.insert(150);
    bst.insert(250);    // this will be a new root

    ASSERT_EQ(bst.remove(200), true);

    int N =  -1; // nullptr_marker
    auto actual = debug::dump(bst, N);

    std::vector<int> expected = {
             100,
         50,
       N,   N,
                   250,
                150,
               N,  N,
                       N
    };
    ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
}
