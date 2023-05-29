//
// Created by Joao on 5/12/2023.
//

#include "CvsReader.h"
//Used for the real world graphs
std::vector<Node> CvsReader::readNodes(const std::string &filepath) {
    std::vector<Node> nodes;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Error opening the following file path: " << filepath << std::endl;
        return nodes;
    }

    std::string index, latitude, longitude;

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)){
        std::istringstream iss(line);

        std::getline(iss, index, ',');
        std::getline(iss, longitude, ',');
        std::getline(iss, latitude, ',');

        nodes.emplace_back(std::stoi(index), std::stol(latitude), std::stol(longitude));
    }

    file.close();
    return nodes;
}

std::vector<Edge> CvsReader::readEdges(const std::string &filepath) {
    return std::vector<Edge>();
}


