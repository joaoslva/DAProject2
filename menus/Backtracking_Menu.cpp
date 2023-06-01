//
// Created by franc on 31/05/2023.
//

#include "Backtracking_Menu.h"

Backtracking_Menu::Backtracking_Menu(const Graph &graph, const int &graph_loaded): Menu(graph,graph_loaded) {}

bool Backtracking_Menu::verifyGraphType() {

    if (graph_loaded == 0){
        std::cout << "|                                                           |\n";
        std::cout << "| You haven't loaded any graph yet. To use Backtracking     |\n";
        std::cout << "| use a small graph (like the Toy Graphs or the Extra ones),|\n";
        std::cout << "| due to this algorithm's high computational complexity!    |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        return false;
    }

    else if(graph_loaded == 3){
        std::cout << "|                                                           |\n";
        std::cout << "| You appear to have loaded a Real-world graph. Since you   |\n";
        std::cout << "| don't wan't to be were waiting 1000 years for the program |\n";
        std::cout << "| to finish, please load a small graph (like the Toy Graphs |\n";
        std::cout << "| or the Extra ones), due to this algorithm's high          |\n";
        std::cout << "| computational complexity!                                 |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        return false;
    }
    return true;
}

bool Backtracking_Menu::start() {
    if(!verifyGraphType()) return true;

    std::string backtrackingChoice;

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| - BACKTRACKING MENU -                                     |\n";

    while(true){
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Run the algorithm                                     |\n";
        std::cout << "| 2 - See a short description of the algorithm              |\n";
        std::cout << "| r - Return to the main menu                               |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, backtrackingChoice);
        std::cout << "|                                                           |\n";

        if(backtrackingChoice == "1"){

        }

        else if(backtrackingChoice == "2"){
            algorithmDescription();
        }

        else if(backtrackingChoice == "r"){
            returnMessage();
            return true;
        }

        else if(backtrackingChoice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
            std::cout << "| Select one of the options bellow:                         \n";
        }
    }
}

void Backtracking_Menu::algorithmDescription() {
    std::cout << "|-------------------Algorithm Description-------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| The Backtracking algorithm is a brute force algorithm that|\n";
    std::cout << "| tries to find the best solution by trying all the possible|\n";
    std::cout << "| combinations of paths, by using a recursive approach. It  |\n";
    std::cout << "| is a very slow algorithm, but it is guaranteed to find the|\n";
    std::cout << "| best solution.                                            |\n";
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
}