#include "trie.hpp"
#include <vector>
#include <iostream>

void bubble_sort(std::vector<int> & vec){
    int size = static_cast<int>(vec.size());
    for (int i {0} ; i < size -1; i++){
        for (int j {0}; j < size -i-1; j++){
            if (vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}
    
void selection_sort(std::vector<int> & vec){
    int i {0};
    int j {0};
    int min {0};
    int size {static_cast<int>(vec.size())};
    while (i < size){
        j= i+1;
        min = i;
        while (j <= size){ // Trouver le min
            if (vec[j] < vec[min]){
                min = j;
            }
            j = j+1;
        }
        if (min != i){ //On fait l'échange si c'est pas pareil
            std::swap(vec[i], vec[min]);
        }
        i+=1;
    }
}


void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size { middle - left + 1 };
    size_t const right_size { right - middle };
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index {0};
    size_t right_index {0};

    size_t index {left};

    // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size &&   right_index < right_size) {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] < right_vec[right_index]) {
            vec[index] = left_vec[left_index];
            left_index++;
        } else {
            vec[index] = right_vec[right_index];
            right_index++;
        }
        index++;
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index < left_size) {
        vec[index] = left_vec[left_index];
        left_index++;
        index++;
    }
    while (right_index < right_size) {
        vec[index] = right_vec[right_index];
        right_index++;
        index++;
    }
}

void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    }
    // 1. Choix de l'index au milieu de la partition
    // 2. Appels récursifs sur les deux sous-parties
    // 3. Fusion des deux sous-parties

    //trouver le milieu
    size_t middle {(left + right) / 2};

    //diviser
    merge_sort(vec, left, middle);
    merge_sort(vec, middle + 1, right);

    //fusionner
    merge_sort_merge(vec, left, middle, right);

}