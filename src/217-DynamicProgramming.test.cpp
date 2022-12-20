#include "217-DynamicProgramming.h"

#include <gtest/gtest.h>
#include <iostream>

TEST(inefficient_fibonacci, normal_test)
{
    using namespace n217;

    std::vector<uint32_t> expected{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233};
    std::vector<uint32_t> actual;

    for (uint32_t n = 0; n < expected.size(); n++)
    {
        actual.emplace_back(inefficient_fibonacci(n));
    }

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}

TEST(dybamic_fibonacci, normal_test)
{
    using namespace n217;

    constexpr uint32_t MAX = 10;
    std::vector<uint32_t> expected;
    std::vector<uint32_t> actual;

    for (uint32_t n = 0; n < MAX; n++)
    {
        expected.emplace_back(inefficient_fibonacci(n));
    }

    for (uint32_t n = 0; n < MAX; n++)
    {
        actual.emplace_back(dynamic_fibonacci(n));
    }

    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}
