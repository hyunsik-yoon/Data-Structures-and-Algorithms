#include "118-StackWithLinkedList.h"

#include <gtest/gtest.h>

TEST(stack_with_linked_list, empty)
{
    n118::Stack<int> stack;
    
    ASSERT_EQ(stack.is_empty(), true);
}

TEST(stack_with_linked_list, push_and_pop)
{
    n118::Stack<int> stack;
    
    ASSERT_EQ(stack.is_empty(), true);

    stack.push(100);

    ASSERT_EQ(stack.is_empty(), false);
    ASSERT_EQ(stack.pop(), 100);
    ASSERT_EQ(stack.is_empty(), true);
}

TEST(stack_with_linked_list, pushes_and_pops)
{
    n118::Stack<int> stack;

    stack.push(100);
    stack.push(200);

    ASSERT_EQ(stack.is_empty(), false);
    ASSERT_EQ(stack.pop(), 200);

    ASSERT_EQ(stack.is_empty(), false);
    ASSERT_EQ(stack.pop(), 100);
    ASSERT_EQ(stack.is_empty(), true);
}
