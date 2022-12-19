#include "205-DepthFirstSearch.h"

#include "132-BinarySearchTree.h"

#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

namespace
{

n132::BinarySearchTree<int32_t> make_binary_search_tree()
{
    n132::BinarySearchTree<int32_t> tree;
    tree.insert(9);
    tree.insert(4);
    tree.insert(20);
    tree.insert(1);
    tree.insert(6);
    tree.insert(15);
    tree.insert(170);

    return tree;
}

} // namespace

TEST(DepthFirstSearch_inorder, empty)
{
    using namespace n205;

    n132::BinarySearchTree<int32_t> tree;

    auto actual = DFSInorder(tree);

    ASSERT_EQ(actual.empty(), true);
}

TEST(DepthFirstSearch_inorder, non_empty_tree)
{
    using namespace n205;

    auto tree = make_binary_search_tree();

    std::vector<int32_t> expected{1, 4, 6, 9, 15, 20, 170};
    auto actual = DFSInorder(tree);

    ASSERT_EQ(std::equal(expected.begin(), expected.end(), actual.begin()), true);
}

TEST(DepthFirstSearch_preorder, empty)
{
    using namespace n205;

    n132::BinarySearchTree<int32_t> tree;

    auto actual = DFSPreorder(tree);

    ASSERT_EQ(actual.empty(), true);
}

TEST(DepthFirstSearch_preorder, non_empty_tree)
{
    using namespace n205;

    auto tree = make_binary_search_tree();

    std::vector<int32_t> expected{9, 4, 1, 6, 20, 15, 170};
    auto actual = DFSPreorder(tree);

    ASSERT_EQ(std::equal(expected.begin(), expected.end(), actual.begin()), true);
}

TEST(DepthFirstSearch_postorder, empty)
{
    using namespace n205;

    n132::BinarySearchTree<int32_t> tree;

    auto actual = DFSPostorder(tree);

    ASSERT_EQ(actual.empty(), true);
}

TEST(DepthFirstSearch_postorder, non_empty_tree)
{
    using namespace n205;

    auto tree = make_binary_search_tree();

    std::vector<int32_t> expected{1, 6, 4, 15, 170, 20, 9};
    auto actual = DFSPostorder(tree);

    ASSERT_EQ(std::equal(expected.begin(), expected.end(), actual.begin()), true);
}
