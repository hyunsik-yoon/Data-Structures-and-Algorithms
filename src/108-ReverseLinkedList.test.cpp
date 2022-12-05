#include "108-ReverseLinkedList.h"

#include <gtest/gtest.h>

TEST(Reverse_Linked_List_test, empty)
{
    using namespace n108;

    ds::LinkedList<int> l;

    reverse(&l);

    ASSERT_EQ(l.head(), nullptr);
    ASSERT_EQ(l.tail(), nullptr);
}

TEST(Reverse_Linked_List_test, one_node)
{
    using namespace n108;

    ds::LinkedList<int> l;

    l.append(1);

    reverse(&l);

    ASSERT_EQ(l.head(), l.tail());
}

TEST(Reverse_Linked_List_test, three_node)
{
    using namespace n108;

    ds::LinkedList<int> l;
    l.append(1);
    l.append(2);
    l.append(3);

    reverse(&l);

    ASSERT_EQ(l.head()->val(), 3);
    ASSERT_EQ(l.head()->next()->val(), 2);
    ASSERT_EQ(l.head()->next()->next()->val(), 1);
    ASSERT_EQ(l.head()->next()->next(), l.tail());
}
