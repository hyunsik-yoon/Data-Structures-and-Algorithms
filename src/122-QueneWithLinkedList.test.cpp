#include "122-QueueWithLinkedList.h"

#include <gtest/gtest.h>

TEST(queue_with_array, empty)
{
    n122::Queue<int> queue;
    
    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_array, push_and_pop)
{
    n122::Queue<int> queue;
    
    ASSERT_EQ(queue.is_empty(), true);

    queue.queue(100);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 100);
    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_array, pushes_and_pops)
{
    n122::Queue<int> queue;

    queue.queue(100);
    queue.queue(200);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 100);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 200);
    ASSERT_EQ(queue.is_empty(), true);
}
