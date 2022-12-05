#include "120-StackWithArray.h"

#include <gtest/gtest.h>

TEST(stack_with_array, empty)
{
    n120::Stack<int> stack;
    
    ASSERT_EQ(stack.is_empty(), true);
}

TEST(stack_with_array, push_and_pop)
{
    n120::Stack<int> stack;
    
    ASSERT_EQ(stack.is_empty(), true);

    stack.push(100);

    ASSERT_EQ(stack.is_empty(), false);
    ASSERT_EQ(stack.pop(), 100);
    ASSERT_EQ(stack.is_empty(), true);
}

TEST(stack_with_array, pushes_and_pops)
{
    n120::Stack<int> stack;

    stack.push(100);
    stack.push(200);

    ASSERT_EQ(stack.is_empty(), false);
    ASSERT_EQ(stack.pop(), 200);

    ASSERT_EQ(stack.is_empty(), false);
    ASSERT_EQ(stack.pop(), 100);
    ASSERT_EQ(stack.is_empty(), true);
}
