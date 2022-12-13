#ifndef __149__GRAPH__
#define __149__GRAPH__

#include <stdexcept>
#include <set>
#include <map>
#include <memory>

namespace n149
{

class Graph
{
public:
    using Vertex = int32_t;
    using Vertexes = std::set<Vertex>;
    using PtrVertexes = std::unique_ptr<Vertexes>;

    void add_new_vertex(Vertex v)
    {
        auto found = _graph.find(v);
        if (found != _graph.end())
        {
            throw std::runtime_error("Vertex already exists");
        }

        _graph[v] = std::make_unique<Vertexes>();
    }

    void add_edge(Vertex v1, Vertex v2)
    {
        auto find1 = _graph.find(v1);
        if (find1 == _graph.end())
        {
            throw std::runtime_error("v1 does not exist.");
        }

        auto find2 = _graph.find(v2);
        if (find2 == _graph.end())
        {
            throw std::runtime_error("v2 does not exist.");
        }

        auto &p1_vertexes = find1->second;
        p1_vertexes->insert(v2);

        auto &p2_vertexes = find2->second;
        p2_vertexes->insert(v1);
    }

    const Vertexes &get_conntected_vertexes(Vertex v)
    {
        auto found = _graph.find(v);
        if (found == _graph.end())
        {
            throw std::runtime_error("Vertex does not exist");
        }

        return *found->second.get();
    }

private:
    // NOTE
    // Why PtrVertexes ?
    // 1) std::map<Vertex, Vertexes> needs to call copy constructor, requiring redundant memory copy
    // 2) std::map<Vertex, Vertexes*> needs to implement destructor to free memory for Vertexes
    // 3) std::map<Vertex, PtrVertexes> does not need destructor to free memory for Vertexes
    std::map<Vertex, PtrVertexes> _graph;
};

} // namespace n149

#endif // __149__GRAPH__
