#include "85-RecuringElementInArray.h"

#include <gtest/gtest.h>

TEST(Recuring_Element_In_Array_test, empty)
{
    std::vector<int> arr = {};
    try 
    {
        find_recurring_elem(arr);
        FAIL();
    } 
    catch(NoRecurringElemException &e) 
    {
        SUCCEED();
    }
}

TEST(Recuring_Element_In_Array_test, non_recurring_elem)
{
    std::vector<int> arr = {1, 2, 3};
    try 
    {
        find_recurring_elem(arr);
        FAIL();
    } 
    catch(NoRecurringElemException &e) 
    {
        SUCCEED();
    }
}

TEST(Recuring_Element_In_Array_test, recurring_elem)
{
    std::vector<int> arr = {1, 2, 3, 2};
    try 
    {
        auto ans = find_recurring_elem(arr);
        ASSERT_EQ(ans, 2);
    } 
    catch(...) 
    {
        FAIL();
    }
}
