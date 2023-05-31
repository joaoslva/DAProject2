//
// Created by franc on 31/05/2023.
//

#ifndef PROJETO_2_LOAD_GRAPH_MENU_H
#define PROJETO_2_LOAD_GRAPH_MENU_H


#include "Menu.h"

class Load_Graph_Menu: public Menu{
    public:
        bool start();
        void helpLoadMenu();
        bool toyGraphs();
        bool extendedGraphs();
        bool realWorldGraphs();
        void graphLoaded();

};


#endif //PROJETO_2_LOAD_GRAPH_MENU_H
