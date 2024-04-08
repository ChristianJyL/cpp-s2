#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes){
    std::unordered_map<std::string, std::vector<float>> map {};
    for (std::pair<std::string, float> const& robot_fix : robots_fixes) {
        map[robot_fix.first].push_back(robot_fix.second);
    }
    return map;
}

//Question 2 
float sum(std::vector<float> const& vec){
    return std::accumulate(vec.begin(), vec.end(), 0.0f, [](float acc, float current_element) { return acc + current_element; });
}

void displaySumEachRobot(std::vector<std::pair<std::string, float>> const& robots_fixes){
    std::unordered_map<std::string, std::vector<float>> map { robots_fixes_map(robots_fixes) };
    std::cout << "Voici la somme des coûts de réparation pour chaque robot : " << std::endl;
    for (std::pair<std::string, std::vector<float>> const& robot_fix : map) {
        std::cout << robot_fix.first << " : " << sum(robot_fix.second) << std::endl;
    }
}


int main() {
    std::vector<std::pair<std::string, float>> robots_fixes { get_robots_fix(50) };
    std::unordered_map<std::string, std::vector<float>> map { robots_fixes_map(robots_fixes) };

    std::cout << "La liste random des réparations : " << std::endl;
    for (std::pair<std::string, float> const& robot_fix : robots_fixes) {
        std::cout << robot_fix.first << " : " << robot_fix.second << std::endl;
    }

    std::cout << "Les réparations par robot : " << std::endl;
    for (std::pair<std::string, std::vector<float>> const& robot_fix : map) {
        std::cout << robot_fix.first << " : ";
        for (float const& cost : robot_fix.second) {
            std::cout << cost << " ";
        }
        std::cout << std::endl;
    }

    displaySumEachRobot(robots_fixes);

    
    
    return 0;
}