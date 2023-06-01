//
// Created by franc on 31/05/2023.
//

#ifndef PROJETO_2_TRIANGULAR_MENU_H
#define PROJETO_2_TRIANGULAR_MENU_H


#include "Menu.h"

class Triangular_Menu: public Menu {
    public:
    bool verifyGraphType();
    bool start();
    explicit Triangular_Menu(const Graph &graph, const int &graph_loaded);

};


#endif //PROJETO_2_TRIANGULAR_MENU_H
