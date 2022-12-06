#include "122-Queue.h"

#include <gtest/gtest.h>

TEST(queue_with_linked_list, empty)
{
    using namespace n122;
    Queue<int, DS::LinkedList> queue;

    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_linked_list, push_and_pop)
{
    using namespace n122;
    Queue<int, DS::LinkedList> queue;

    ASSERT_EQ(queue.is_empty(), true);

    queue.queue(100);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 100);
    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_linked_list, pushes_and_pops)
{
    using namespace n122;
    Queue<int, DS::LinkedList> queue;

    queue.queue(100);
    queue.queue(200);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 100);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 200);
    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_array, empty)
{
    using namespace n122;
    Queue<int, DS::Array> queue(3);

    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_array, push_and_pop)
{
    using namespace n122;
    Queue<int, DS::Array> queue(3);

    ASSERT_EQ(queue.is_empty(), true);

    queue.queue(100);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 100);
    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_array, pushes_and_pops)
{
    using namespace n122;
    Queue<int, DS::Array> queue(3);

    queue.queue(100);
    queue.queue(200);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 100);

    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.dequeue(), 200);
    ASSERT_EQ(queue.is_empty(), true);
}

TEST(queue_with_array, pushes_and_pops_2)
{
    using namespace n122;
    Queue<int, DS::Array> queue(3);

    queue.queue(100);
    queue.queue(200);
    queue.queue(300);

    ASSERT_EQ(queue.dequeue(), 100);
    queue.queue(400);

    ASSERT_EQ(queue.dequeue(), 200);
    queue.queue(500);

    ASSERT_EQ(queue.dequeue(), 300);
    ASSERT_EQ(queue.dequeue(), 400);
    queue.queue(600);
    queue.queue(700);

    ASSERT_EQ(queue.dequeue(), 500);
    ASSERT_EQ(queue.dequeue(), 600);
    ASSERT_EQ(queue.is_empty(), false);

    ASSERT_EQ(queue.dequeue(), 700);
    ASSERT_EQ(queue.is_empty(), true);
}
