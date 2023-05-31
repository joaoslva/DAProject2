//
// Created by franc on 31/05/2023.
//

#include "Load_Graph_Menu.h"

bool Load_Graph_Menu::start(){
    bool running = true;
    //TODO Create a dope print saying "Train Management App" with characters

    std::cout << "\n|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    //description of the project
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (running){
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



        if(choice == "4")
            helpLoadMenu();

        else if(choice == "q"){
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