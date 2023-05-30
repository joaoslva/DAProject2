#include <iostream>
#include "Graph.h"

int main() {
    Graph graph;
    graph.createToyGraph("../data_sets/Toy-Graphs/Toy-Graphs/shipping.csv");
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    graph.clearNodes();
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    graph.createToyGraph("../data_sets/Toy-Graphs/Toy-Graphs/stadiums.csv");
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    graph.clearNodes();
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    graph.createToyGraph("../data_sets/Toy-Graphs/Toy-Graphs/tourism.csv");
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    graph.clearNodes();
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
