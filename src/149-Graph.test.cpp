#include "149-Graph.h"

#include <gtest/gtest.h>

#include <cassert>

TEST(Graph, error_cases)
{
    n149::Graph g;

    ASSERT_ANY_THROW(g.get_conntected_vertexes(0));

    g.add_new_vertex(0);
    ASSERT_ANY_THROW(g.add_edge(0, 1));

    ASSERT_ANY_THROW(g.add_new_vertex(0));
}

TEST(Graph, scenario_1)
{
    n149::Graph g;

    g.add_new_vertex(0);
    g.add_new_vertex(1);
    g.add_new_vertex(2);
    g.add_new_vertex(3);
    g.add_new_vertex(4);
    g.add_new_vertex(5);
    g.add_new_vertex(6);

    g.add_edge(3, 1);
    g.add_edge(3, 4);
    g.add_edge(4, 2);
    g.add_edge(4, 5);
    g.add_edge(1, 2);
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(6, 5);

    auto vertexes = g.get_conntected_vertexes(0);
    {
        ASSERT_EQ(vertexes.size(), 2);
        ASSERT_TRUE(vertexes.find(1) != vertexes.end());
        ASSERT_TRUE(vertexes.find(2) != vertexes.end());
    }
    vertexes = g.get_conntected_vertexes(1);
    {
        ASSERT_EQ(vertexes.size(), 3);
        ASSERT_TRUE(vertexes.find(0) != vertexes.end());
        ASSERT_TRUE(vertexes.find(2) != vertexes.end());
        ASSERT_TRUE(vertexes.find(3) != vertexes.end());
    }
    // let's move to the last vertex
    vertexes = g.get_conntected_vertexes(6);
    {
        ASSERT_EQ(vertexes.size(), 1);
        ASSERT_TRUE(vertexes.find(5) != vertexes.end());
    }
}
