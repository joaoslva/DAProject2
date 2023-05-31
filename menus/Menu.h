
#ifndef PROJETO_2_MENU_H
#define PROJETO_2_MENU_H

#include <iostream>
#include <limits>
#include <string>
#include <unistd.h>
#include <iomanip>
#include "../Graph.h"


class Menu {
protected:
    Graph graph;
    int graph_loaded; //0 - Not set; 1 - Toy Graph; 2 - Extra Connected; 3 - Real World
public:
    Menu();

    void start();
    void helpMainMenu();
    void returnMessage();
    void quitMessage();
    bool feedbackLoop();

};


#endif //PROJETO_2_MENU_H
