#include "108-ReverseLinkedList.h"

#include <gtest/gtest.h>

TEST(Reverse_Linked_List_test, empty)
{
    using namespace n108;

    LinkedList l;

    reverse(&l);

    ASSERT_EQ(l.head(), nullptr);
    ASSERT_EQ(l.tail(), nullptr);
}

TEST(Reverse_Linked_List_test, one_node)
{
    using namespace n108;

    LinkedList l;
    Node node(1);

    l.head(&node);
    l.tail(&node);

    reverse(&l);

    ASSERT_EQ(l.head(), &node);
    ASSERT_EQ(l.tail(), &node);
}

TEST(Reverse_Linked_List_test, three_node)
{
    using namespace n108;

    LinkedList l;
    Node node1(1);
    Node node2(2);
    Node node3(3);

    node1.next(&node2);
    node2.next(&node3);

    l.head(&node1);
    l.tail(&node3);

    reverse(&l);

    ASSERT_EQ(l.head(), &node3);
    ASSERT_EQ(l.tail(), &node1);

    ASSERT_EQ(node3.next(), &node2);
    ASSERT_EQ(node2.next(), &node1);
    ASSERT_EQ(node1.next(), nullptr);
}
