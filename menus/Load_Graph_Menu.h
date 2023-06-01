//
// Created by franc on 31/05/2023.
//

#ifndef PROJETO_2_LOAD_GRAPH_MENU_H
#define PROJETO_2_LOAD_GRAPH_MENU_H


#include "Menu.h"

class Load_Graph_Menu: public Menu{
    public:

        /**
        * @brief Starts the Load Graph menu and handles user input.
        * @return Returns true if the program should continue running, false otherwise.
        * @note The time complexity of this function depends on the user input and the operations performed in the menu.
        */
        bool start();
        
        
        /**
        * @brief Displays the help menu for the Load Graph menu and handles user input.
        * @note The time complexity of this function depends on the user input and the operations performed in the menu.
        */
        void helpLoadMenu();
        

        /**
        * @brief Displays the Toy Graphs menu, handles user input, and loads the chosen graph.
        * @return Returns true if the program should continue running, false otherwise.
        * @note The time complexity of this function depends on the user input and the operations performed in the menu.
        */
        bool toyGraphs();
        
        
        /**
        * @brief Displays the Extended Graphs menu, handles user input, and loads the chosen graph.
        * @return Returns true if the program should continue running, false otherwise.
        * @note The time complexity of this function depends on the user input and the operations performed in the menu.
        */
        bool extendedGraphs();
        
        
        /**
        * @brief Displays the Real World Graphs menu, handles user input, and loads the chosen graph.
        * @return Returns true if the program should continue running, false otherwise.
        * @note The time complexity of this function depends on the user input and the operations performed in the menu.
        */
        bool realWorldGraphs();
        
        
        /**
        * @brief Displays a message indicating that the chosen graph was loaded successfully.
        * @note The time complexity of this function is O(1).
        */
        void graphLoaded();

        explicit Load_Graph_Menu(const Graph &graph, const int &graph_loaded);

};


#endif //PROJETO_2_LOAD_GRAPH_MENU_H
