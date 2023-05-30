
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
public:
    explicit Menu(const Graph &graph);
    void start();
    void help();
    void returnMessage();
    void quitMessage();
};


#endif //PROJETO_2_MENU_H
