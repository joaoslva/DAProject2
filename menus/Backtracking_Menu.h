//
// Created by franc on 31/05/2023.
//

#ifndef PROJETO_2_BACKTRACKING_MENU_H
#define PROJETO_2_BACKTRACKING_MENU_H


#include "Menu.h"

class Backtracking_Menu: public Menu{
public:
    /**
    * @brief Verifies the type of the loaded graph and displays a message if no graph is loaded.
    * @note If a graph isn´t loaded, a message is displayed to inform the user about the need to load a small graph.
    * @note The time complexity of this function is O(1).
    */
    bool verifyGraphType();
    
    bool start();

    static void algorithmDescription();

};


#endif //PROJETO_2_BACKTRACKING_MENU_H
