#include "73-MergeSortedArrays.h"

#include <gtest/gtest.h>

TEST(merge_sorted_arrays_test, two_empty)
{
    {
        std::vector<int> a = {};
        std::vector<int> b = {};
        std::vector<int> expected = {};
        auto actual = merge_sorted_arrays(a, b);

        ASSERT_EQ(actual.size(), expected.size());
    }
}

TEST(merge_sorted_arrays_test, one_empty)
{
    {
        std::vector<int> a = {};
        std::vector<int> b = {1, 2, 3};
        std::vector<int> expected = {1, 2, 3};
        auto actual = merge_sorted_arrays(a, b);

        ASSERT_EQ(actual.size(), expected.size());
        for (uint32_t x = 0; x < expected.size(); x++)
        {
            ASSERT_EQ(actual[x], expected[x]);
        }
    }
}

TEST(merge_sorted_arrays_test, two_not_empty)
{
    {
        std::vector<int> a = {0, 3, 4};
        std::vector<int> b = {1, 2, 5};
        std::vector<int> expected = {0, 1, 2, 3, 4, 5};
        auto actual = merge_sorted_arrays(a, b);

        ASSERT_EQ(actual.size(), expected.size());
        for (uint32_t x = 0; x < expected.size(); x++)
        {
            ASSERT_EQ(actual[x], expected[x]);
        }
    }
}

TEST(merge_sorted_arrays_test, same_value)
{
    {
        std::vector<int> a = {1, 2, 5};
        std::vector<int> b = {1, 2, 5};
        std::vector<int> expected = {1, 1, 2, 2, 5, 5};
        auto actual = merge_sorted_arrays(a, b);

        ASSERT_EQ(actual.size(), expected.size());
        for (uint32_t x = 0; x < expected.size(); x++)
        {
            ASSERT_EQ(actual[x], expected[x]);
        }
    }
}
