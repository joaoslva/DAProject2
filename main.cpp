#include <iostream>
#include "Graph.h"

int main() {
    Graph graph;
    graph.createRealWorldGraph("../data_sets/Real-world Graphs/graph3/nodes.csv","../data_sets/Real-world Graphs/graph3/edges.csv");
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    graph.clearNodes();
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
