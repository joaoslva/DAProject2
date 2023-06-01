#include <iostream>
#include "Graph.h"
#include "menus/Menu.h"

int main() {
    Graph g;
    Menu menu = Menu(g,0);
    menu.start();
    return 0;
}
