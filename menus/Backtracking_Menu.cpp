//
// Created by franc on 31/05/2023.
//

#include "Backtracking_Menu.h"

void Backtracking_Menu::verifyGraphType() {
    if (graph_loaded == 0){
        std::cout << "|                                                           |\n";
        std::cout << "| You haven't loaded any graph yet. To use Backtracking     |\n";
        std::cout << "| use a small graph (like the Toy Graphs), due to its       |\n";
        std::cout << "| high computational complexity!                            |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
    }
}