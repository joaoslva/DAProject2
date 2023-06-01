//
// Created by gakes on 30/05/2023.
//

#include "Menu.h"
#include "Backtracking_Menu.h"
#include "Triangular_Menu.h"
#include "Other_Heuristics_Menu.h"


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
            running = startLoadMenu();
        }

        else if(choice == "2"){
            Backtracking_Menu backtrackingMenu = Backtracking_Menu(graph, graph_loaded);
            running = backtrackingMenu.start();
        }

        else if (choice == "3"){
            double dist = graph.triangularApproximationHeuristic();
            std::cout << "The approximate distance is " << dist << " meters\n";
        }

        else if(choice == "4") {
            printf("Under construction\n");
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

bool Menu::startLoadMenu() {
    bool running;

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
        std::string choice;
        std::cout << "| - Load Graph -                                            |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Toy Graph                                             |\n";
        std::cout << "| 2 - Extra Fully Connected Graph                           |\n";
        std::cout << "| 3 - Real World Graph                                      |\n";
        std::cout << "| 4 - Help                                                  |\n";
        std::cout << "| r - Return to prev page                                   |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        if(choice == "1") {
            running = toyGraphs();
            if (!running) return false;
            break;
        }

        else if(choice == "2"){
            running = extendedGraphs();
            if (!running) return false;
            break;
        }

        else if(choice == "3"){
            running = realWorldGraphs();
            if (!running) return false;
            break;
        }

        else if(choice == "4"){
            helpLoadMenu();
        }

        else if(choice == "r"){
            returnMessage();
            return true;
        }

        else if(choice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
        }
    }

    return true;
}


void Menu::helpLoadMenu() {
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

bool Menu::toyGraphs(){

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
        std::string choice;
        std::cout << "| - Toy Graphs -                                            |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Shipping                                              |\n";
        std::cout << "| 2 - Stadiums                                              |\n";
        std::cout << "| 3 - Tourism                                               |\n";
        std::cout << "| r - Return to prev page                                   |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        if(choice == "1") {
            graph.clearNodes();
            graph.createToyGraph("../data_sets/Toy-Graphs/shipping.csv");
            graph_loaded = 1;
            break;
        }


        else if(choice == "2"){
            graph.clearNodes();
            graph.createToyGraph("../data_sets/Toy-Graphs/stadiums.csv");
            graph_loaded = 1;
            break;
        }

        else if(choice == "3"){
            graph.clearNodes();
            graph.createToyGraph("../data_sets/Toy-Graphs/tourism.csv");
            graph_loaded = 1;
            break;
        }

        else if(choice == "r"){
            returnMessage();
            return true;
        }

        else if(choice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
        }
    }
    graphLoaded();
    returnMessage();
    return true;
}

bool Menu::extendedGraphs() {
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
        std::string choice;
        std::cout << "| - Extended Graphs -                                       |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Type the number of edges you want to use between these    |\n";
        std::cout << "| values:                                                   |\n";
        std::cout << "|             | 25 | 100 | 300 | 500 | 700 | 900 |          |\n";
        std::cout << "|                | 50 | 200 | 400 | 600 | 800 |             |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| r - Return to prev page                                   |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your value: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        int choiceNum;
        try {
            choiceNum = std::stoi(choice);
        } catch (const std::invalid_argument& e) {
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
            continue;
        }

        if ((choiceNum >= 100 && choiceNum <= 900 && choiceNum % 100 == 0) || choiceNum == 25 || choiceNum == 50) {
            graph.clearNodes();
            graph.createExtraGraphs("../data_sets/Extra_Fully_Connected_Graphs/edges_" + choice + ".csv");
            graph_loaded = 2;
            break;
        }

        else if(choice == "r"){
            returnMessage();
            return true;
        }

        else if(choice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
        }
    }
    graphLoaded();
    returnMessage();
    return true;
}

bool Menu::realWorldGraphs() {

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "| WARNING: These graphs are very dense, so their creation   |\n";
    std::cout << "| might take several seconds (for the 1st graph) or even    |\n";
    std::cout << "| several minutes (specially for graph 3). Beware of that   |\n";
    std::cout << "| before proceeding!!!                                      |\n";
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
        std::string choice;
        std::cout << "| - Real World Graphs -                                     |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Graph 1 (1000 nodes)                                  |\n";
        std::cout << "| 2 - Graph 2 (5000 nodes)                                  |\n";
        std::cout << "| 3 - Graph 3 (10000 nodes)                                 |\n";
        std::cout << "| r - Return to prev page                                   |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        if(choice == "1") {
            graph.clearNodes();
            graph.createRealWorldGraph("../data_sets/Real-world Graphs/graph1/nodes.csv", "../data_sets/Real-world Graphs/graph1/edges.csv");
            graph_loaded = 3;
            break;
        }


        else if(choice == "2"){
            graph.clearNodes();
            graph.createRealWorldGraph("../data_sets/Real-world Graphs/graph2/nodes.csv", "../data_sets/Real-world Graphs/graph2/edges.csv");
            graph_loaded = 3;
            break;
        }

        else if(choice == "3"){
            graph.clearNodes();
            graph.createRealWorldGraph("../data_sets/Real-world Graphs/graph3/nodes.csv", "../data_sets/Real-world Graphs/graph3/edges.csv");
            graph_loaded = 3;
            break;
        }

        else if(choice == "r"){
            returnMessage();
            return true;
        }

        else if(choice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
        }
    }
    graphLoaded();
    returnMessage();
    return true;
}

void Menu::graphLoaded() {
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "|         The chosen Graph was loaded successfully!         |\n";
}
