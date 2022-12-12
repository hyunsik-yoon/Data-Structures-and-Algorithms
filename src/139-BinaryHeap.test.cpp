#include "139-BinaryHeap.h"

#include <gtest/gtest.h>
#include <algorithm>

TEST(binary_heap, empty)
{
    using namespace n139;

    BinaryHeap<BHType::MAX, int> binary_heap;

    SUCCEED();
}

TEST(binary_heap, insert_1)
{
    using namespace n139;

    BinaryHeap<BHType::MAX, int> binary_heap;
    {
        binary_heap.insert(30);
        binary_heap.insert(50);
        /*
                50
            30
        */
        auto &actual = binary_heap.as_vector();
        std::vector<int> expected({50, 30});
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
    }
    {
        binary_heap.insert(70);
        /*
                70
            30     50
        */
        auto actual = binary_heap.as_vector();
        std::vector<int> expected({70, 30, 50});
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
    }
    {
        binary_heap.insert(40);
        /*
                    70
                40     50
              30
        */
        auto actual = binary_heap.as_vector();
        std::vector<int> expected({70, 40, 50, 30});
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), expected.begin()));
    }
    {
        binary_heap.insert(80);
        /*
                    80
                70     50
              30  40
        */
        auto actual = binary_heap.as_vector();
        std::initializer_list<int> expected = {80, 70, 50, 30, 40};
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), std::vector<int>(expected).begin()));
    }
}

TEST(binary_heap, remove_top)
{
    using namespace n139;

    BinaryHeap<BHType::MAX, int> binary_heap;
    /*
                80
            70     50
          30  40
    */
    binary_heap.insert(80);
    binary_heap.insert(70);
    binary_heap.insert(50);
    binary_heap.insert(30);
    binary_heap.insert(40);

    ASSERT_EQ(binary_heap.remove_top(), 80);
    {
        /*
                    70
                40     50
            30
        */
        auto actual = binary_heap.as_vector();
        std::initializer_list<int> expected = {70, 40, 50, 30};
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), std::vector<int>(expected).begin()));
    }

    ASSERT_EQ(binary_heap.remove_top(), 70);
    {
        /*
                    50
                40     30
        */
        auto actual = binary_heap.as_vector();
        std::initializer_list<int> expected = {50, 40, 30};
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), std::vector<int>(expected).begin()));
    }

    ASSERT_EQ(binary_heap.remove_top(), 50);
    {
        /*
                    40
                30
        */
        auto actual = binary_heap.as_vector();
        std::initializer_list<int> expected = {40, 30};
        ASSERT_TRUE(std::equal(actual.begin(), actual.end(), std::vector<int>(expected).begin()));
    }

    ASSERT_EQ(binary_heap.remove_top(), 40);
    ASSERT_EQ(binary_heap.remove_top(), 30);
    ASSERT_EQ(binary_heap.is_empty(), true);
}
