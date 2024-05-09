#include <iostream>
#include <vector>
#include "graph.hpp"

int main()
{

    std::vector<std::vector<float>> adjacency_matrix {
        {0.0, 1.0, 0.0, 0.0}, //0 0->1
        {1.0, 0.0, 1.0, 0.0}, //1 1->0 1->2
        {0.0, 1.0, 0.0, 1.0}, //2 2->1 2->3
        {0.0, 0.0, 1.0, 0.0}  //3 3->2

    };

    Graph::WeightedGraph graph_from_function = Graph::build_from_adjacency_matrix(adjacency_matrix);

    Graph::WeightedGraph graph_from_la_mano;
    for (int i {0}; i < adjacency_matrix.size(); i++){
        graph_from_la_mano.add_vertex(i);
    }
    graph_from_la_mano.add_undirected_edge(0, 1);
    graph_from_la_mano.add_undirected_edge(1, 2);
    graph_from_la_mano.add_undirected_edge(2, 3);

    if (graph_from_function == graph_from_la_mano){
        std::cout << "Les deux graphes sont égaux" << std::endl;
    } else {
        std::cout << "Les deux graphes ne sont pas égaux" << std::endl;
    }

    return 0;
}
