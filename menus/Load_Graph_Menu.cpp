//
// Created by franc on 31/05/2023.
//

#include "Load_Graph_Menu.h"

bool Load_Graph_Menu::start(){
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
            running = toyGraphs();
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


void Load_Graph_Menu::helpLoadMenu() {
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

bool Load_Graph_Menu::toyGraphs(){

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

bool Load_Graph_Menu::extendedGraphs() {
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

void Load_Graph_Menu::graphLoaded() {
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "|         The chosen Graph was loaded successfully!         |\n";
}