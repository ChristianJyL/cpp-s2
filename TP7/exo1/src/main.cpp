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

    //exemple du cours
    Graph::WeightedGraph graph;
    graph.add_vertex(0);
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);
    graph.add_vertex(6);
    
    graph.add_directed_edge(0, 1);
    graph.add_directed_edge(0, 2);
    graph.add_directed_edge(1, 3);
    graph.add_directed_edge(1, 4);
    graph.add_directed_edge(2, 5);
    graph.add_directed_edge(2, 6);

    graph.print_DFS(0);
    graph.print_BFS(0);

    Graph::WeightedGraph dijkstraGraph ; //exemple du cours
    dijkstraGraph.add_vertex(0);
    dijkstraGraph.add_vertex(1);
    dijkstraGraph.add_vertex(2);
    dijkstraGraph.add_vertex(3);
    dijkstraGraph.add_vertex(4);

    dijkstraGraph.add_directed_edge(0,1,1);
    dijkstraGraph.add_directed_edge(0,2,2);
    dijkstraGraph.add_directed_edge(1,2,1);
    dijkstraGraph.add_directed_edge(2,3,3);
    dijkstraGraph.add_directed_edge(1,3,5);
    dijkstraGraph.add_directed_edge(2,4,6);
    dijkstraGraph.add_directed_edge(3,4,2);

    std::unordered_map<int, std::pair<float, int>> result = Graph::dijkstra(dijkstraGraph, 0, 4);
    for (auto const& [node, pair] : result){
        std::cout << "Node : " << node << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }


    return 0;
}
