
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



    /**
    * @brief Verifies if a graph is loaded.
    * The function checks if a graph is already loaded by checking the value of the `graph_loaded` variable. If `graph_loaded` is 0, indicating that no graph is loaded, it displays a message informing the user to load a graph suitable for the Backtracking algorithm. The function returns true if a graph is loaded, and false otherwise.
    * @return True if a graph is loaded, false otherwise.
    * @note Time complexity: The time complexity of this function is constant, O(1), as it performs a simple comparison and returns the result.
    */
    bool verifyLoadedGraph();

    /**
    * @brief Performs a feedback loop, allowing the user to provide input until a valid input is received.
    * @return A boolean value indicating whether to stay in the loop (true) or return to the previous page (false).
    * @note The loop continues until the user enters 'back' to return to the previous page or provides a valid input.
    * @note The time complexity of this function depends on the user input and the operations performed in the loop.
    */
    bool feedbackLoop();



    /**
 * @brief Displays the description of an algorithm.
 * @param menu An integer specifying the algorithm description to display.
 * @note The function displays a description of the specified algorithm based on the provided menu parameter. It prints the description of the Backtracking algorithm if menu is 1, the Triangular Approximation Heuristic if menu is 2, and the description of another custom algorithm if menu is 3. The function does not return any value.
 * @note Time complexity: The time complexity of this function is constant, O(1), as it performs a simple print operation based on the value of the menu parameter.
 */
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



    /**
    * @brief Starts the Backtracking menu.
    * The function verifies if the graph type is suitable for the Backtracking algorithm. If the graph type is not compatible, it returns to the main menu. Otherwise, it displays the options in the Backtracking menu. The user can choose to run the algorithm, see a description of the algorithm, return to the main menu, or quit the program. Invalid inputs prompt the user to select a valid option.
    * @return True if the user chose to return to the main menu, false if the user chose to quit the program.
    * @note Time complexity: The time complexity of this function is constant, O(1), as it performs a fixed set of operations regardless of the graph type or input.
    */
    bool startBacktrackingMenu();



    /**
    * @brief Runs the Backtracking algorithm and displays the result.
    * The function executes the Backtracking algorithm to find the shortest path in the graph. It calculates the minimum distance and displays the result, including the shortest path and the total time elapsed. The time complexity of the algorithm depends on the size of the graph.
    * @note Time complexity: The Backtracking algorithm has an exponential time complexity, typically O(n!), where n is the number of nodes in the graph. However, the actual time complexity may vary based on the specific implementation and graph characteristics.
    */
    void backtrackingAlgorithm();

    /*
     * -----------TRIANGULAR APPROXIMATION HEURISTIC MENU----------- *
     */
    /**
    * @brief Starts the menu for the Triangular Approximation Heuristic.
    * @return True if the menu should continue, false if the program should quit.
    * @note If the loaded graph is not valid, the function returns true immediately.
    * @note Time complexity: O(n), where n is the number of options in the menu.
    */
    bool startTriApproxMenu();



    /**
    * @brief Runs the Triangular Approximation Heuristic algorithm.
    * @note The algorithm calculates the approximate distance and displays the result.
    * @note Time complexity: O(n), where n is the number of nodes in the graph.
    */
    void triApproxAlgorithm();

    /*
     * -----------OTHER HEURISTIC MENU----------- *
     */

    /**
    * @brief Starts the menu for the Other Heuristics.
    * @return True if the menu should continue, false if the program should quit.
    * @note If the loaded graph is not valid, the function returns true immediately.
    * @note Time complexity: O(n), where n is the number of options in the menu.
    */
    bool startOtherHeuristicsMenu();



    /**
    * @brief Runs the Heuristic we created.
    * @note The algorithm calculates the approximate distance and displays the result.
    * @note Time complexity: O(n), where n is the number of nodes in the graph.
    */
    void ourHeuristicsAlgorithm();

    /**
    * @brief Runs the Closest Neighbour Heuristic.
    * @note The algorithm calculates the approximate distance and displays the result.
    * @note Time complexity: O(n), where n is the number of nodes in the graph.
    */
    void closestNeighbourAlgorithm();
};




#endif //PROJETO_2_MENU_H
