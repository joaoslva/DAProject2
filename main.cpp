#include <iostream>
#include "code/Graph.h"
#include "code/Menu.h"

int main() {
    Graph g;
    Menu menu = Menu(g,0);
    menu.start();
    return 0;
}
