//
// Created by franc on 31/05/2023.
//

#include "Triangular_Menu.h"

Triangular_Menu::Triangular_Menu(const Graph &graph, const int &graph_loaded) : Menu(graph, graph_loaded) {}

bool Triangular_Menu::verifyGraphType() {
    if (graph_loaded == 0){
        std::cout << "|                                                           |\n";
        std::cout << "| You haven't loaded any graph yet. To use the Triangular   |\n";
        std::cout << "| Approximation Heuristic, you must use on of the Real      |\n";
        std::cout << "| World Graphs!!!                                           |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        return false;
    }
    else if (graph_loaded != 3){
        std::cout << "|                                                           |\n";
        std::cout << "| Invalid graph type. To use the Triangular Approximation   |\n";
        std::cout << "| Heuristic, you must use on of the Real World Graphs!!     |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        return false;
    }
    return true;
}

bool Triangular_Menu::start() {
    if(!verifyGraphType()){
        return true;
    }
    double dist = graph.triangularApproximationHeuristic();
    std::cout << "The approximate distance is " << dist << " meters\n";
    return true;
}
