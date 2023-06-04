#include "Menu.h"


Menu::Menu(const Graph &graph, const int &graph_loaded): graph(graph), graph_loaded(graph_loaded) {}

void Menu::start(){
    bool running = true;

    std::cout << "\n|---------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "|        - GRAPH TSP ROUTING ALGORITHMS APP 2000 -          |\n";
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (running){
        std::string choice;
        std::cout << "| - MAIN MENU -                                             |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Load Graph                                            |\n";
        std::cout << "| 2 - Backtracking Algorithm                                |\n";
        std::cout << "| 3 - Triangular Approximation Heuristic                    |\n";
        std::cout << "| 4 - Other Heuristics                                      |\n";
        std::cout << "| 5 - Help                                                  |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        if (choice == "1"){
            running = startLoadMenu();
        }

        else if(choice == "2"){
            running = startBacktrackingMenu();
        }

        else if (choice == "3"){
            running = startTriApproxMenu();
        }

        else if(choice == "4") {
            running = startOtherHeuristicsMenu();
        }

        else if(choice == "5")
            helpMainMenu();

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

void Menu::helpMainMenu() {
    std::cout << "|------------------------Help Page--------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| 1 - Load Graph: In this option you can load a graph from  |\n";
    std::cout << "|     a file. There are 3 types of graphs you can load: Toy |\n";
    std::cout << "|     Graphs, Extra Connected Graphs and Real World Graphs. |\n";
    std::cout << "| 2 - Backtracking Algorithm: In this option you can run    |\n";
    std::cout << "|     the backtracking algorithm to find the shortest path  |\n";
    std::cout << "|     connecting all the nodes in the graph.                |\n";
    std::cout << "| 3 - Triangular Approximation Heuristic: In this option    |\n";
    std::cout << "|     you can run the Triangular Approximation Heuristic to |\n";
    std::cout << "|     find the shortest path connecting all the nodes in    |\n";
    std::cout << "|     the graph.                                            |\n";
    std::cout << "| 4 - Other Heuristics: In this option you can run other    |\n";
    std::cout << "|     heuristics created by us to find the shortest path    |\n";
    std::cout << "|     connecting all the nodes in the graph.                |\n";
    std::cout << "|                                                           |\n";
    std::cout << "| To use the program, first you need to load a graph. Then  |\n";
    std::cout << "| you can run the algorithms to find the shortest path.     |\n";
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
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

bool Menu::feedbackLoop() {
    std::string helpChoice;
    while (true) {
        std::getline(std::cin, helpChoice);
        std::cout << "|                                                           |\n";

        if (helpChoice == "back") {
            returnMessage();
            return false;
        } else if (helpChoice == "stay"){
            return true;

        } else {
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Enter here: ";
        }
    }
}

bool Menu::startLoadMenu() {
    bool running;

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
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

        if(choice == "1") {
            running = toyGraphs();
            if (!running) return false;
            break;
        }

        else if(choice == "2"){
            running = extendedGraphs();
            if (!running) return false;
            break;
        }

        else if(choice == "3"){
            running = realWorldGraphs();
            if (!running) return false;
            break;
        }

        else if(choice == "4"){
            helpLoadMenu();
        }

        else if(choice == "r"){
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

    return true;
}


void Menu::helpLoadMenu() {
    bool running = true;
    while(running) {
        std::string helpChoice;

        std::cout << "|------------------------Help Page--------------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Toy Graph: In this option you can load small graphs   |\n";
        std::cout << "|     with a small number of nodes and edges.               |\n";
        std::cout << "| 2 - Extra Fully Connected Graph: In this option you can   |\n";
        std::cout << "|     load bigger graphs that are fully connected.          |\n";
        std::cout << "| 3 - Real World Graph: In this option you can load graphs  |\n";
        std::cout << "|     that represent real world scenarios.                  |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Write 'back' to go to the previous page                   |\n";
        std::cout << "| Enter here: ";
        running = feedbackLoop();
    }
}

bool Menu::toyGraphs(){

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
        std::string choice;
        std::cout << "| - Toy Graphs -                                            |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Shipping                                              |\n";
        std::cout << "| 2 - Stadiums                                              |\n";
        std::cout << "| 3 - Tourism                                               |\n";
        std::cout << "| r - Return to prev page                                   |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        if(choice == "1") {
            graph.clearNodes();
            graph.createToyGraph("../data_sets/Toy-Graphs/shipping.csv");
            graph_loaded = 1;
            break;
        }


        else if(choice == "2"){
            graph.clearNodes();
            graph.createToyGraph("../data_sets/Toy-Graphs/stadiums.csv");
            graph_loaded = 1;
            break;
        }

        else if(choice == "3"){
            graph.clearNodes();
            graph.createToyGraph("../data_sets/Toy-Graphs/tourism.csv");
            graph_loaded = 1;
            break;
        }

        else if(choice == "r"){
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
    graphLoaded();
    returnMessage();
    return true;
}

bool Menu::extendedGraphs() {
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
        std::string choice;
        std::cout << "| - Extended Graphs -                                       |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Type the number of edges you want to use between these    |\n";
        std::cout << "| values:                                                   |\n";
        std::cout << "|             | 25 | 100 | 300 | 500 | 700 | 900 |          |\n";
        std::cout << "|                | 50 | 200 | 400 | 600 | 800 |             |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| r - Return to prev page                                   |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your value: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        int choiceNum;
        try {
            choiceNum = std::stoi(choice);
        } catch (const std::invalid_argument& e) {
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
            continue;
        }

        if ((choiceNum >= 100 && choiceNum <= 900 && choiceNum % 100 == 0) || choiceNum == 25 || choiceNum == 50) {
            graph.clearNodes();
            graph.createExtraGraphs("../data_sets/Extra_Fully_Connected_Graphs/edges_" + choice + ".csv");
            graph_loaded = 2;
            break;
        }

        else if(choice == "r"){
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
    graphLoaded();
    returnMessage();
    return true;
}

bool Menu::realWorldGraphs() {

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "| WARNING: These graphs are very dense, so their creation   |\n";
    std::cout << "| might take several seconds (for the 1st graph) or even    |\n";
    std::cout << "| several minutes (specially for graph 3). Beware of that   |\n";
    std::cout << "| before proceeding!!!                                      |\n";
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";

    while (true){
        std::string choice;
        std::cout << "| - Real World Graphs -                                     |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Graph 1 (1000 nodes)                                  |\n";
        std::cout << "| 2 - Graph 2 (5000 nodes)                                  |\n";
        std::cout << "| 3 - Graph 3 (10000 nodes)                                 |\n";
        std::cout << "| r - Return to prev page                                   |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, choice);
        std::cout << "|                                                           |\n";

        if(choice == "1") {
            graph.clearNodes();
            graph.createRealWorldGraph("../data_sets/Real-world Graphs/graph1/nodes.csv", "../data_sets/Real-world Graphs/graph1/edges.csv");
            graph_loaded = 3;
            break;
        }


        else if(choice == "2"){
            graph.clearNodes();
            graph.createRealWorldGraph("../data_sets/Real-world Graphs/graph2/nodes.csv", "../data_sets/Real-world Graphs/graph2/edges.csv");
            graph_loaded = 3;
            break;
        }

        else if(choice == "3"){
            graph.clearNodes();
            graph.createRealWorldGraph("../data_sets/Real-world Graphs/graph3/nodes.csv", "../data_sets/Real-world Graphs/graph3/edges.csv");
            graph_loaded = 3;
            break;
        }

        else if(choice == "r"){
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
    graphLoaded();
    returnMessage();
    return true;
}

void Menu::graphLoaded() {
    std::cout << "|                                                           |\n";
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "|         The chosen Graph was loaded successfully!         |\n";
}

bool Menu::verifyLoadedGraph() {
    if(graph_loaded == 0){
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| You haven't loaded any graph yet. To use Backtracking     |\n";
        std::cout << "| use a small graph (like the Toy Graphs or the Extra ones),|\n";
        std::cout << "| due to this algorithm's high computational complexity!    |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        return false;
    }
    return true;
}

bool Menu::verifyGraphTypeBacktracking() {
    if (graph_loaded == 0){
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| You haven't loaded any graph yet. To use Backtracking     |\n";
        std::cout << "| use a small graph (like the Toy Graphs or the Extra ones),|\n";
        std::cout << "| due to this algorithm's high computational complexity!    |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        return false;
    }

    else if(graph_loaded == 3){
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| You appear to have loaded a Real-world graph. Since you   |\n";
        std::cout << "| don't want to be were waiting 1000 years for the program |\n";
        std::cout << "| to finish, please load a small graph (like the Toy Graphs |\n";
        std::cout << "| or the Extra ones), due to this algorithm's high          |\n";
        std::cout << "| computational complexity!                                 |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        return false;
    }
    return true;
}

bool Menu::startBacktrackingMenu() {
    if(!verifyGraphTypeBacktracking()) return true;

    std::string backtrackingChoice;

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| - BACKTRACKING MENU -                                     |\n";

    while(true){
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Run the algorithm                                     |\n";
        std::cout << "| 2 - See a short description of the algorithm              |\n";
        std::cout << "| r - Return to the main menu                               |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, backtrackingChoice);
        std::cout << "|                                                           |\n";

        if(backtrackingChoice == "1"){
            backtrackingAlgorithm();
        }

        else if(backtrackingChoice == "2"){
            algorithmDescription(1);
        }

        else if(backtrackingChoice == "r"){
            returnMessage();
            return true;
        }

        else if(backtrackingChoice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
            std::cout << "| Select one of the options bellow:                         \n";
        }
    }
}

void Menu::algorithmDescription(int menu) {
    if (menu == 1) {
        std::cout << "|-------------------Algorithm Description-------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| The Backtracking algorithm is a brute force algorithm that|\n";
        std::cout << "| tries to find the best solution by trying all the possible|\n";
        std::cout << "| combinations of paths, by using a recursive approach. It  |\n";
        std::cout << "| is a very slow algorithm, but it is guaranteed to find the|\n";
        std::cout << "| best solution.                                            |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| - BACKTRACKING MENU -                                     |\n";
    }
    else if (menu == 2){
        std::cout << "|-------------------Algorithm Description-------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| The Triangular Approximation Heuristic is a greedy        |\n";
        std::cout << "| algorithm that tries to find the best solution by always  |\n";
        std::cout << "| choosing the nearest neighbour. Therefore, the result is  |\n";
        std::cout << "| not guaranteed to be the best solution, because it relies |\n";
        std::cout << "| on the assumption that the nearest neighbour is the best  |\n";
        std::cout << "| choice and also because even if the nearest neighbour     |\n";
        std::cout << "| isn't connected to the current node, it will still be     |\n";
        std::cout << "| chosen by an approximation.                               |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| - TRIANGULAR APPROXIMATION MENU -                          |\n";
    }
    else if(menu == 3){
        std::cout << "|-------------------Algorithm Description-------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| This sections has two different algorithms:               |\n";
        std::cout << "| The first one is the one that we created, inspired by the |\n";
        std::cout << "| Christofides algorithm. The algorithm starts similarly,   |\n";
        std::cout << "| by building an MST. Then, it will try to complete the     |\n";
        std::cout << "| path by adding the shortest edges that are not in the MST |\n";
        std::cout << "| and that don't create a cycle. To do so, it uses a func-  |\n";
        std::cout << "| tion that we created, that finds the shortest shortcut    |\n";
        std::cout << "| between two nodes. Finally, it finds the Eulerian circuit |\n";
        std::cout << "| of the graph using a adapted version of the Nearest       |\n";
        std::cout << "| Neighbour algorithm and outputs the path and the distance. |\n";
        std::cout << "| The second one is the Near Neighbour algorithm, adapted   |\n";
        std::cout << "| to our data structures. It is a greedy algorithm that     |\n";
        std::cout << "| tries to find the best solution by always choosing the    |\n";
        std::cout << "| nearest neighbour. Therefore, the result is not guaranteed|\n";
        std::cout << "| to be the best solution, because it relies on the         |\n";
        std::cout << "| assumption that the nearest neighbour is the best choice  |\n";
        std::cout << "| and also because even if the nearest neighbour isn't      |\n";
        std::cout << "| connected to the current node, it will still be chosen by |\n";
        std::cout << "| an approximation.                                         |\n";
        std::cout << "|                                                           |\n";
        std::cout << "|-----------------------------------------------------------|\n";
        std::cout << "|                                                           |\n";
        std::cout << "| - OTHER HEURISTICS MENU -                                 |\n";
    }
}

void Menu::backtrackingAlgorithm() {
    std::vector<Node*> path;
    auto start = std::chrono::high_resolution_clock::now();
    double minDistance = graph.TSPBacktracking(path);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::string minDistanceString = std::to_string(minDistance);


    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| The shortest path found has a distance of ";

    std::cout << minDistance;
    std::cout << " meters";

    for(int i = 0; i < 5; i++){
        std::cout << " ";
    }

    std::cout << "|\n";
    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds";
    for(int i = 0; i < 59 - 29 - std::to_string(elapsed.count()).length(); i++){
        std::cout << " ";
    }
    std::cout << "|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| Do you wish to see the path?                              |\n";
    std::cout << "| Enter here your choice (yes/no): ";
    std::string choice;
    while (true){
        std::getline(std::cin, choice);
        if(choice == "yes"){
            int charCounter = 1;
            std::cout << "|                                                           |\n";
            std::cout << "| The path is:                                              |\n";
            std::cout << "| ";
            for(int i = 0; i < path.size(); i++){
                charCounter += (4 + std::to_string(path[i]->getIndex()).length());
                if (charCounter > 58){
                    for(int j = 0; j < 59 - charCounter + std::to_string(path[i]->getIndex()).length() + 4; j++){
                        std::cout << " ";
                    }
                    std::cout << "|\n";
                    std::cout << "| ";
                    charCounter = (1 + 4 + std::to_string(path[i]->getIndex()).length());
                }
                if(i == path.size() - 1){
                    std::cout << path[i]->getIndex();
                    charCounter -= 4;
                }
                else{
                    std::cout << path[i]->getIndex() << " -> ";
                }
            }
            charCounter += 5;
            if(charCounter > 58){
                for(int j = 0; j < 59 - charCounter; j++){
                    std::cout << " ";
                }
                std::cout << "| \n";
                charCounter = 5;
            }

            std::cout << " -> 0";
            for(int j = 0; j < 59 - charCounter; j++){
                std::cout << " ";
            }

            std::cout << "|\n";
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - BACKTRACKING MENU -                                     |\n";
            break;
        }
        else if(choice == "no"){
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - BACKTRACKING MENU -                                     |\n";
            break;
        }
        else{
            std::cout << "|                                                           |\n";
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Do you wish to see the path?                              |\n";
            std::cout << "| Enter here your choice (yes/no): ";
        }
    }
}

bool Menu::startTriApproxMenu() {
    if(!verifyLoadedGraph()) return true;

    std::string triAproxChoice;

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| - TRIANGULAR APPROXIMATION HEURISTIC MENU -               |\n";

    while(true){
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Run the algorithm                                     |\n";
        std::cout << "| 2 - See a short description of the algorithm              |\n";
        std::cout << "| r - Return to the main menu                               |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, triAproxChoice);
        std::cout << "|                                                           |\n";

        if(triAproxChoice == "1"){
            triApproxAlgorithm();
        }

        else if(triAproxChoice == "2"){
            algorithmDescription(2);
        }

        else if(triAproxChoice == "r"){
            returnMessage();
            return true;
        }

        else if(triAproxChoice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
            std::cout << "| Select one of the options bellow:                         \n";
        }
    }
}

void Menu::triApproxAlgorithm() {
    std::vector<Node*> path;

    auto start = std::chrono::high_resolution_clock::now();
    double dist = graph.triangularApproximationHeuristic(path);
    auto finish = std::chrono::high_resolution_clock::now();
    std::string minDistanceString = std::to_string(dist);
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "| The approximate distance is ";
    std::cout << dist;
    std::cout << " meters";
    for(int i = 0; i < 59 - 40; i++){
        std::cout << " ";
    }
    std::cout << "|\n";

    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds";
    for(int i = 0; i < 59 - 29 - std::to_string(elapsed.count()).length(); i++){
        std::cout << " ";
    }

    std::cout << "|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| Do you wish to see the path?                              |\n";
    std::cout << "| Enter here your choice (yes/no): ";
    std::string choice;
    while (true){
        std::getline(std::cin, choice);
        if(choice == "yes"){
            int charCounter = 1;
            std::cout << "|                                                           |\n";
            std::cout << "| The path is:                                              |\n";
            std::cout << "| ";
            for(int i = 0; i < path.size(); i++){
                charCounter += (4 + std::to_string(path[i]->getIndex()).length());
                if (charCounter > 58){
                    for(int j = 0; j < 59 - charCounter + std::to_string(path[i]->getIndex()).length() + 4; j++){
                        std::cout << " ";
                    }
                    std::cout << "|\n";
                    std::cout << "| ";
                    charCounter = (1 + 4 + std::to_string(path[i]->getIndex()).length());
                }
                if(i == path.size() - 1){
                    std::cout << path[i]->getIndex();
                    charCounter -= 4;
                }
                else{
                    std::cout << path[i]->getIndex() << " -> ";
                }
            }

            for(int j = 0; j < 59 - charCounter; j++){
                std::cout << " ";
            }

            std::cout << "|\n";
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - TRIANGULAR APPROXIMATION HEURISTIC MENU -               |\n";
            break;
        }
        else if(choice == "no"){
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - TRIANGULAR APPROXIMATION HEURISTIC MENU -               |\n";
            break;
        }
        else{
            std::cout << "|                                                           |\n";
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Do you wish to see the path?                              |\n";
            std::cout << "| Enter here your choice (yes/no): ";
        }
    }
}

bool Menu::startOtherHeuristicsMenu() {
    if(!verifyLoadedGraph()) return true;

    std::string otherHeuristicsChoice;

    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| - OTHER HEURISTICS MENU -                                 |\n";
    while(true){
        std::cout << "|                                                           |\n";
        std::cout << "| 1 - Run our heuristic!                                    |\n";
        std::cout << "| 2 - Run closest neighbour heuristic                       |\n";
        std::cout << "| 3 - See a short description of the algorithm              |\n";
        std::cout << "| r - Return to the main menu                               |\n";
        std::cout << "| q - Quit the program                                      |\n";
        std::cout << "|                                                           |\n";
        std::cout << "| Enter here your choice: ";
        std::getline(std::cin, otherHeuristicsChoice);
        std::cout << "|                                                           |\n";

        if(otherHeuristicsChoice == "1"){
            ourHeuristicsAlgorithm();
        }

        else if(otherHeuristicsChoice == "2"){
            closestNeighbourAlgorithm();
        }

        else if(otherHeuristicsChoice == "3"){
            algorithmDescription(3);
        }

        else if(otherHeuristicsChoice == "r"){
            returnMessage();
            return true;
        }

        else if(otherHeuristicsChoice == "q"){
            quitMessage();
            return false;
        }

        else{
            std::cout << "| Not a valid input, please try again                      \n";
            std::cout << "|                                                          \n";
            std::cout << "| Select one of the options bellow:                         \n";
        }
    }
}

void Menu::ourHeuristicsAlgorithm() {
    std::vector<int> path;

    auto start = std::chrono::high_resolution_clock::now();
    double dist = graph.ourHeuristic(path);
    auto finish = std::chrono::high_resolution_clock::now();
    std::string minDistanceString = std::to_string(dist);
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "| The approximate distance is ";
    std::cout << dist;
    std::cout << " meters";
    for(int i = 0; i < 59 - 40; i++){
        std::cout << " ";
    }
    std::cout << "|\n";
    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds";
    for(int i = 0; i < 59 - 30 - std::to_string(elapsed.count()).length(); i++){
        std::cout << " ";
    }
    std::cout << "|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| Do you wish to see the path?                              |\n";
    std::cout << "| Enter here your choice (yes/no): ";
    std::string choice;
    while (true){
        std::getline(std::cin, choice);
        if(choice == "yes"){
            int charCounter = 1;
            std::cout << "|                                                           |\n";
            std::cout << "| The path is:                                              |\n";
            std::cout << "| ";
            for(int i = 0; i < path.size(); i++){
                charCounter += (4 + std::to_string(path[i]).length());
                if (charCounter > 58){
                    for(int j = 0; j < 59 - charCounter + std::to_string(path[i]).length() + 4; j++){
                        std::cout << " ";
                    }
                    std::cout << "|\n";
                    std::cout << "| ";
                    charCounter = (1 + 4 + std::to_string(path[i]).length());
                }
                if(i == path.size() - 1){
                    std::cout << path[i];
                    charCounter -= 4;
                }
                else{
                    std::cout << path[i] << " -> ";
                }
            }

            for(int j = 0; j < 59 - charCounter; j++){
                std::cout << " ";
            }

            std::cout << "|\n";
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - OTHER HEURISTICS MENU -                                 |\n";
            break;
        }
        else if(choice == "no"){
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - OTHER HEURISTICS MENU -                                 |\n";
            break;
        }
        else{
            std::cout << "|                                                           |\n";
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Do you wish to see the path?                              |\n";
            std::cout << "| Enter here your choice (yes/no): ";
        }
    }
}

void Menu::closestNeighbourAlgorithm() {
    std::vector<int> path;

    auto start = std::chrono::high_resolution_clock::now();
    double dist = graph.closestNeighbour(path);
    auto finish = std::chrono::high_resolution_clock::now();
    std::string minDistanceString = std::to_string(dist);
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "| The approximate distance is ";
    std::cout << dist;
    std::cout << " meters";
    for(int i = 0; i < 59 - 40; i++){
        std::cout << " ";
    }
    std::cout << "|\n";
    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds";
    for(int i = 0; i < 59 - 30 - std::to_string(elapsed.count()).length(); i++){
        std::cout << " ";
    }
    std::cout << "|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| Do you wish to see the path?                              |\n";
    std::cout << "| Enter here your choice (yes/no): ";
    std::string choice;
    while (true){
        std::getline(std::cin, choice);
        if(choice == "yes"){
            int charCounter = 1;
            std::cout << "|                                                           |\n";
            std::cout << "| The path is:                                              |\n";
            std::cout << "| ";
            for(int i = 0; i < path.size(); i++){
                charCounter += (4 + std::to_string(path[i]).length());
                if (charCounter > 58){
                    for(int j = 0; j < 59 - charCounter + std::to_string(path[i]).length() + 4; j++){
                        std::cout << " ";
                    }
                    std::cout << "|\n";
                    std::cout << "| ";
                    charCounter = (1 + 4 + std::to_string(path[i]).length());
                }
                if(i == path.size() - 1){
                    std::cout << path[i];
                    charCounter -= 4;
                }
                else{
                    std::cout << path[i] << " -> ";
                }
            }

            for(int j = 0; j < 59 - charCounter; j++){
                std::cout << " ";
            }

            std::cout << "|\n";
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - OTHER HEURISTICS MENU -                                 |\n";
            break;
        }
        else if(choice == "no"){
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - OTHER HEURISTICS MENU -                                 |\n";
            break;
        }
        else{
            std::cout << "|                                                           |\n";
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Do you wish to see the path?                              |\n";
            std::cout << "| Enter here your choice (yes/no): ";
        }
    }
}