#include "LinkedList.h"

#include <gtest/gtest.h>

TEST(Linked_test, empty)
{
    ds::LinkedList<int> l;

    ASSERT_EQ(l.head(), nullptr);
    ASSERT_EQ(l.tail(), nullptr);
}

TEST(Linked_test, append)
{
    ds::LinkedList<int> l;

    l.append(100);

    ASSERT_TRUE(l.head() != nullptr);
    ASSERT_TRUE(l.tail() == l.head());
    ASSERT_EQ(l.head()->val(), 100);

    l.append(200);

    ASSERT_TRUE(l.head() != nullptr);
    ASSERT_TRUE(l.tail() != l.head());
    ASSERT_EQ(l.head()->val(), 100);
    ASSERT_EQ(l.head()->next()->val(), 200);
    ASSERT_EQ(l.tail(), l.head()->next());
    ASSERT_EQ(l.head()->next()->next(), nullptr);
}

TEST(Linked_test, insert_head)
{
    ds::LinkedList<int> l;

    l.insert_head(200);

    ASSERT_TRUE(l.head() != nullptr);
    ASSERT_TRUE(l.tail() == l.head());
    ASSERT_EQ(l.head()->val(), 200);

    l.insert_head(100);

    ASSERT_TRUE(l.head() != nullptr);
    ASSERT_TRUE(l.tail() != l.head());
    ASSERT_EQ(l.head()->val(), 100);
    ASSERT_EQ(l.head()->next()->val(), 200);
    ASSERT_EQ(l.tail(), l.head()->next());
    ASSERT_EQ(l.head()->next()->next(), nullptr);
}

TEST(Linked_test, remove_head)
{
    ds::LinkedList<int> l;

    l.insert_head(100);
    l.append(200);

    ASSERT_EQ(l.head()->val(), 100);
    ASSERT_EQ(l.head()->next()->val(), 200);
    ASSERT_EQ(l.head()->next(), l.tail());

    ASSERT_EQ(l.remove_head(), 100);
    ASSERT_EQ(l.remove_head(), 200);
    ASSERT_EQ(l.is_empty(), true);
    ASSERT_THROW(l.remove_head(), std::runtime_error);
}
