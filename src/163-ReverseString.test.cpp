#include "163-ReverseString.h"

#include <gtest/gtest.h>

#include <cassert>

TEST(Reverse_string, empty)
{
    std::string str = "";

    auto rev = n163::Solution().reverse(str);

    ASSERT_EQ(rev, "");
}

TEST(Reverse_string, reverse)
{
    {
        std::string str = "1";

        auto rev = n163::Solution().reverse(str);

        ASSERT_EQ(rev, "1");
    }
    {
        std::string str = "12345";

        auto rev = n163::Solution().reverse(str);

        ASSERT_EQ(rev, "54321");
    }
}
