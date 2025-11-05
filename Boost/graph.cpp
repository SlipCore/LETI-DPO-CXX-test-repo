#include <iostream>
#include <boost/graph/adjacency_iterator.hpp>
#include <boost/graph/graphviz.hpp>

// edge information
struct EdgeProperties {
    double weight;
};

//declaration of graph type
using Graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::directedS,
    boost::no_property,
    EdgeProperties
>;

template<typename GraphT>
void print_adjacent_vertices(GraphT const& g) {
    using vertex_descriptor = typename boost::graph_traits<GraphT>::vertex_descriptor;
    using edge_iterator = typename boost::graph_traits<GraphT>::out_edge_iterator;

    // loop over vertexes
    for (vertex_descriptor v: boost::make_iterator_range(vertices(g))) {
        std::cout << "Vertex: " << v << ": ";

        // adjacent vertexes
        for (edge_iterator ei = out_edges(v, g).first; ei != out_edges(v, g).second; ++ei) {
            vertex_descriptor target_vertex = boost::target(*ei, g);
            std::cout << target_vertex << "(" << g[*ei].weight << ")";
        }

        std::cout << "\n";
    }

}

int main() {
    Graph g;
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);

    add_edge(0, 1, EdgeProperties{10}, g);
    add_edge(0, 2, EdgeProperties{15}, g);
    add_edge(1, 2, EdgeProperties{5}, g);
    add_edge(2, 0, EdgeProperties{3}, g);

    print_adjacent_vertices(g);

    return 0;
}
