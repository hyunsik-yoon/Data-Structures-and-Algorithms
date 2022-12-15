#include "170-191-Sorting.h"

#include <gtest/gtest.h>

#include <algorithm>

namespace
{
    const std::vector<uint32_t> data = {8, 5, 2, 9, 4, 0, 1, 6, 3, 7};
    const std::vector<uint32_t> expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

TEST(sorting_test, bubble_sort_test)
{
    std::vector<uint32_t> actual = data;

    sorting::bubble_sort(actual);

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}

TEST(sorting_test, selection_sort_test)
{
    std::vector<uint32_t> actual = data;

    sorting::selection_sort(actual);

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}

TEST(sorting_test, insertion_sort_test)
{
    std::vector<uint32_t> actual = data;

    sorting::insertion_sort(actual);

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}

TEST(sorting_test, merge_sort_test)
{
    auto actual = sorting::merge_sort(data);

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}
