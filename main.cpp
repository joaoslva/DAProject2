#include <iostream>
#include "Graph.h"
#include "menus/Menu.h"

int main() {
    Graph graph;
    graph.createToyGraph("../data_sets/Toy-Graphs/stadiums.csv");
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    graph.clearNodes();
    std::cout << "Graph size: " << graph.getNodes().size() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    Graph g;
    Menu menu = Menu(g,0);
    menu.start();
    return 0;
}
