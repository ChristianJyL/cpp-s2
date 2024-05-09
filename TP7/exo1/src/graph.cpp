#include "graph.hpp"
#include <iostream>
#include <vector>

namespace Graph{

    void WeightedGraph::add_vertex(int const id) {
        auto it = adjacency_list.find(id);
        if (it == adjacency_list.end()){ //pas dans la list
            adjacency_list[id];
        }
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight){
        add_vertex(from);
        add_vertex(to);
        adjacency_list[from].push_back({to, weight});
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
        WeightedGraph result ;
        for (int i {0}; i< adjacency_matrix.size() ; i++){
            for (int j {0}; j < adjacency_matrix.size(); j++){
                if (adjacency_matrix[i][j] != 0.0){ //si il y a bien un lien du coup
                    result.add_directed_edge(i,j, adjacency_matrix[i][j]);
                }
            }
        }
        return result;
    }
        




} // namespace Graph
