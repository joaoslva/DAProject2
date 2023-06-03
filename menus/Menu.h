
#ifndef PROJETO_2_MENU_H
#define PROJETO_2_MENU_H

#include <iostream>
#include <limits>
#include <string>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include "../Graph.h"

class Menu {
protected:
    Graph graph;
    int graph_loaded; //0 - Not set; 1 - Toy Graph; 2 - Extra Connected; 3 - Real World
public:
    explicit Menu(const Graph &graph, const int &graph_loaded);


    /**
    * @brief Starts the menu and allows the user to navigate through different options.
    * @note The time complexity of this function depends on the user input and the operations performed in the menu.
    */
    void start();
    
    
    /**
    * @brief Displays the help page for the main menu and allows the user to navigate back to the previous page.
    * @note If the user enters 'back', the function returns to the previous page.
    * @note The time complexity of this function depends on the user input and the operations performed in the menu.
    */
    void helpMainMenu();
    
    
    /**
    * @brief Displays a return message to the user after completing a task or operation.
    * @note The message prompts the user to select one of the options to get started.
    * @note The time complexity of this function is O(1).
    */
    void returnMessage();
    
    
    /**
    * @brief Displays a quit message to the user when the program is exiting.
    * @note The message thanks the user for using the program and wishes them a nice day.
    * @note The time complexity of this function is O(1).
    */
    void quitMessage();
    
    bool verifyLoadedGraph();

    /**
    * @brief Performs a feedback loop, allowing the user to provide input until a valid input is received.
    * @return A boolean value indicating whether to stay in the loop (true) or return to the previous page (false).
    * @note The loop continues until the user enters 'back' to return to the previous page or provides a valid input.
    * @note The time complexity of this function depends on the user input and the operations performed in the loop.
    */
    bool feedbackLoop();


    static void algorithmDescription(int menu);




    /*
     * -----------LOAD GRAPH MENU----------- *
     */

    /**
        * @brief Starts the Load Graph menu and handles user input.
        * @return Returns true if the program should continue running, false otherwise.
        * @note The time complexity of this function depends on the user input and the operations performed in the menu.
        */
    bool startLoadMenu();


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

    /*
     * -----------BACKTRACKING MENU----------- *
     */

    /**
    * @brief Verifies the type of the loaded graph and displays a message if no graph is loaded.
    * @note If a graph isn´t loaded, a message is displayed to inform the user about the need to load a small graph.
    * @note The time complexity of this function is O(1).
    */
    bool verifyGraphTypeBacktracking();

    bool startBacktrackingMenu();

    void backtrackingAlgorithm();

    /*
     * -----------TRIANGULAR APPROXIMATION HEURISTIC MENU----------- *
     */

    bool startTriApproxMenu();

    void triApproxAlgorithm();

    /*
     * -----------OTHER HEURISTIC MENU----------- *
     */

    bool startOtherHeuristicsMenu();

    void otherHeuristicsAlgorithm();
};




#endif //PROJETO_2_MENU_H
