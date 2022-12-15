#include "170-191-Sorting.h"

#include <gtest/gtest.h>

#include <algorithm>

namespace
{
    const std::vector<uint32_t> data_01 = {8, 5, 2, 9, 4, 0, 1, 6, 3, 7};
    const std::vector<uint32_t> expected_01 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    const std::vector<uint32_t> data_02 = {10, 8, 5, 2, 16, 9, 17, 18, 19, 20, 11, 14, 15, 4, 0, 1, 13, 6, 12, 3, 7};
    const std::vector<uint32_t> expected_02 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
};

TEST(sorting_test, bubble_sort_test)
{
    {
        std::vector<uint32_t> actual = data_01;
        sorting::bubble_sort(actual);
        ASSERT_TRUE(std::equal(expected_01.begin(), expected_01.end(), actual.begin()));
    }
    {
        std::vector<uint32_t> actual = data_02;
        sorting::bubble_sort(actual);
        ASSERT_TRUE(std::equal(expected_02.begin(), expected_02.end(), actual.begin()));
    }
}

TEST(sorting_test, selection_sort_test)
{
    {
        std::vector<uint32_t> actual = data_01;
        sorting::selection_sort(actual);
        ASSERT_TRUE(std::equal(expected_01.begin(), expected_01.end(), actual.begin()));
    }
    {
        std::vector<uint32_t> actual = data_02;
        sorting::selection_sort(actual);
        ASSERT_TRUE(std::equal(expected_02.begin(), expected_02.end(), actual.begin()));
    }
}

TEST(sorting_test, insertion_sort_test)
{
    {
        std::vector<uint32_t> actual = data_01;
        sorting::insertion_sort(actual);
        ASSERT_TRUE(std::equal(expected_01.begin(), expected_01.end(), actual.begin()));
    }
    {
        std::vector<uint32_t> actual = data_02;
        sorting::insertion_sort(actual);
        ASSERT_TRUE(std::equal(expected_02.begin(), expected_02.end(), actual.begin()));
    }
}

TEST(sorting_test, merge_sort_test)
{
    {
        auto actual = sorting::merge_sort(data_01);
        ASSERT_TRUE(std::equal(expected_01.begin(), expected_01.end(), actual.begin()));
    }
    {
        auto actual = sorting::merge_sort(data_02);
        ASSERT_TRUE(std::equal(expected_02.begin(), expected_02.end(), actual.begin()));
    }
}
