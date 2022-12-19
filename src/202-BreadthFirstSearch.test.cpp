#include "202-BreadthFirstSearch.h"

#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

TEST(BreathFirstSearch, empty)
{
    using namespace n202;

    BreadthFirstSearhTree<char> tree;

    ASSERT_EQ(tree.is_empty(), true);

    std::vector<char> expected{}; // empty
    std::vector<char> actual = tree.traverse();

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}

TEST(BreathFirstSearch, tree_depth_3)
{
    using namespace n202;

    BreadthFirstSearhTree<uint32_t> tree;
    /*
                    9
                4       20
              1   6   15  170
    */
    tree.insert(9);
    tree.insert(4);
    tree.insert(20);
    tree.insert(1);
    tree.insert(6);
    tree.insert(15);
    tree.insert(170);

    std::vector<uint32_t> expected{9, 4, 20, 1, 6, 15, 170};
    std::vector<uint32_t> actual = tree.traverse();

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}
