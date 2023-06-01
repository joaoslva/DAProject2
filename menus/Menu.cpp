//
// Created by gakes on 30/05/2023.
//

#include "Menu.h"
#include "Load_Graph_Menu.h"
#include "Triangular_Menu.h"

Menu::Menu(const Graph &graph, const int &graph_loaded): graph(graph), graph_loaded(graph_loaded) {}

void Menu::start(){
    bool running = true;
    //TODO Create a dope print saying "Train Management App" with characters

    std::cout << "\n|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    //TODO description of the project
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (running){
        std::string choice;
        std::cout << "| - MAIN MENU -                                             |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Load Graph                                            |\n";
        std::cout << "| 2 - Backtracking Algorithm                                |\n";
        std::cout << "| 3 - Triangular Approximation Heuristic                    |\n";
        std::cout << "| 4 - Other Heuristics                                      |\n";
        std::cout << "| 5 - Help                                                  |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        if (choice == "1"){
            Load_Graph_Menu loadGraphMenu = Load_Graph_Menu(graph, graph_loaded);
            running = loadGraphMenu.start();
        }

        else if (choice == "3"){
            double dist = graph.triangularApproximationHeuristic();
            std::cout << "The approximate distance is " << dist << " meters\n";
        }

        else if(choice == "5")
            helpMainMenu();

        else if(choice == "q"){
            quitMessage();
            running = false;
        }
        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
        }
    }

}

void Menu::helpMainMenu() {
    bool running = true;
    while(running) {
        std::string helpChoice;

        std::cout << "|------------------------Help Page--------------------------|\n";
        std::cout << "|                                                           |\n";
        //TODO help page description
        std::cout << "|                                                           |\n";
        std::cout << "| Write 'back' to go to the previous page                   |\n";
        std::cout << "| Enter here: ";
        running = feedbackLoop();
    }
}


void Menu::returnMessage() {
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| Select one of the options below to get started.           |\n";
    std::cout << "|                                                           |\n";
}

void Menu::quitMessage() {
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| Thank you for using our program, have a nice day!         |\n";
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
}

bool Menu::feedbackLoop() {
    std::string helpChoice;
    while (true) {
        std::getline(std::cin, helpChoice);
        std::cout << "|                                                           |\n";

        if (helpChoice == "back") {
            returnMessage();
            return false;
        } else if (helpChoice == "stay"){
            return true;

        } else {
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Enter here: ";
        }
    }
}
