#include "141-PriorityQueue.h"

#include <gtest/gtest.h>

#include <cassert>
#include <vector>
#include <algorithm>

TEST(Priority_queue, scenario_1)
{
    using namespace n141;

    PriorityQueue<int32_t> pq;

    std::vector<int32_t> priorities = {9, 4, 6, 2, 8, 1, 10};
    for (auto priority: priorities)
    {
        pq.queue(priority);
    }

    // let's sort the list
    std::sort(priorities.begin(), priorities.end(), [](int32_t a, int32_t b){ return a > b; });

    // just in case
    assert(priorities[0] == 10 && priorities[1] == 9);

    for (auto priority: priorities)
    {
        ASSERT_EQ(pq.dequeue(), priority);
    }
}
