//
// Created by gakes on 30/05/2023.
//

#include "Menu.h"

Menu::Menu(const Graph &graph): graph(graph) {}

void Menu::start(){
    bool running = true;
    //Create a dope print saying "Train Management App" with characters

    std::cout << "\n|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    //description of the project
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (running){
        std::string choice;
        std::cout << "| - MAIN MENU -                                             |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 4 - Help                                                  |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";



        if(choice == "4")
            help();

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

void Menu::help() {
    std::string helpChoice;

    std::cout << "|------------------------Help Page--------------------------|\n";
    std::cout << "|                                                           |\n";
//help page description
    std::cout << "|                                                           |\n";
    std::cout << "| Write 'back' to go to the previous page                   |\n";
    std::cout << "| Enter here: ";

    while (true) {
        std::getline(std::cin,helpChoice);
        std::cout << "|                                                           |\n";

        if (helpChoice == "back") {
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Select one of the options below to get started.           |\n";
            std::cout << "|                                                           |\n";
            break;
        } else {
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Enter here: ";
        }
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