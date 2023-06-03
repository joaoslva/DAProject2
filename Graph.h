#ifndef PROJETO_2_GRAPH_H
#define PROJETO_2_GRAPH_H

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

#include "NodeEdge.h"

class Graph {
public:
    /**
    * @brief Destructor for the Graph class.
    * @note Time complexity: O(N^2), where N is the number of nodes in the graph.
    */
    ~Graph();



    /**
    * @brief Creates a real-world graph by reading nodes and edges from files.
    * @param nodesFilePath The path to the file containing node information.
    * @param edgesFilePath The path to the file containing edge information.
    * @return An integer indicating the success or failure of the operation (0 for success, 1 for failure).
    * @note Time complexity: O(N + M), where N is the number of nodes and M is the number of edges.
    */
    int createRealWorldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath);



    /**
    * @brief Creates additional graphs by reading edges from a file.
    * @param edgesFilePath The path to the file containing edge information.
    * @return An integer indicating the success or failure of the operation (0 for success, 1 for failure).
    * @note Time complexity: O(M), where M is the number of edges.
    */
    int createExtraGraphs(const std::string& edgesFilePath);



    /**
    * @brief Creates a toy graph by reading data from a file.
    * @param filePath The path to the file containing graph data.
    * @return An integer indicating the success or failure of the operation (0 for success, 1 for failure).
    * @note Time complexity: O(N + M), where N is the number of nodes and M is the number of edges.
    */
    int createToyGraph(const std::string& filePath);



    /**
    * @brief Adds a new node to the graph.
    * @param nodeIndex The index of the node to be added.
    * @param latitude The latitude of the node.
    * @param longitude The longitude of the node.
    * @return True if the node was added successfully, false if the node already exists.
    * @note Time complexity: O(1).
    */
    bool addNode(const int &nodeIndex, double latitude=0, double longitude=0);



    /**
    * @brief Adds a bidirectional edge between two nodes in the graph.
    * @param sourceIndex The index of the source node.
    * @param destinyIndex The index of the destination node.
    * @param distance The distance between the nodes.
    * @return True if the edge was added successfully, false if either node does not exist.
    * @note Time complexity: O(1).
    */
    bool addBidirectionalEdge(const int &sourceIndex, const int &destinyIndex, double distance);



    /**
    * @brief Finds a node in the graph by its index.
    * @param index The index of the node to find.
    * @return A pointer to the found node, or nullptr if the node is not found.
    * @note Time complexity: O(N), where N is the number of nodes in the graph.
    */
    Node* findNode(int index);



    /**
    * @brief Retrieves all nodes in the graph.
    * @return A vector containing all nodes in the graph.
    * @note Time complexity: O(1).
    */
    std::vector<Node*> getNodes();



    /**
    * @brief Clears all nodes in the graph.
    * @note Time complexity: O(N^2), where N is the number of nodes in the graph.
    */
    void clearNodes();



    /**
    * @brief Computes the minimum spanning tree (MST) of the graph using Prim's algorithm.
    * @return A vector containing all nodes in the MST.
    * @note Time complexity: O((V + E) log V) - where V is the number of vertices and E is the number of edges.
    */
    std::vector<Node *> prim();



    /**
    * @brief Computes the triangular approximation heuristic for the Traveling Salesman Problem (TSP).
    * @param path The minimum distance path based on the triangular approximation heuristic.
    * @return The minimum distance using the triangular approximation heuristic.
    * @note Time complexity: O(n^2) - quadratic complexity.
    */
    double triangularApproximationHeuristic(std::vector<Node *> &path);



    /**
    * @brief Calculates the haversine distance between two coordinates.
    * @param lat1 The latitude of the first coordinate.
    * @param lon1 The longitude of the first coordinate.
    * @param lat2 The latitude of the second coordinate.
    * @param lon2 The longitude of the second coordinate.
    * @return The haversine distance between the two coordinates.
    * @note Time complexity: O(1).
    */
    double static haversine(double lat1, double lon1, double lat2, double lon2);



    /**
    * @brief Converts degrees to radians.
    * @param degrees The angle in degrees.
    * @return The angle converted to radians.
    * @note Time complexity: O(1).
    */
    double static toRadians(double degrees);



    /**
    * @brief Performs backtracking recursion to find the minimum distance path.
    * @param node The current node being visited.
    * @param currentIndex The index of the current node.
    * @param currentDistance The current distance traveled.
    * @param currentPath The current path visited.
    * @param minimumDistance The minimum distance found so far.
    * @param path The minimum distance path.
    * @note Time complexity: O(n!) - exponential complexity.
    */
    void backtrackingRec(Node* node, unsigned int currentIndex, double currentDistance, std::vector<Node*> currentPath, double &minimumDistance, std::vector<Node*> &path);



    /**
    * @brief Solves the Traveling Salesman Problem using backtracking and returns the minimum distance.
    * @param path The minimum distance path.
    * @return The minimum distance of the Traveling Salesman Problem.
    * @note Time complexity: O(n!) - exponential complexity.
    */
    double TSPBacktracking(std::vector<Node*>& path);



    /**
    * @brief Retrieves the number of nodes in the graph.
    * @return The number of nodes in the graph.
    * @note Time complexity: O(1).
    */
    unsigned long getNumNodes() const;



    /**
    * @brief Performs a depth-first search (DFS) to find the path from the source node.
    * @param source The index of the source node.
    * @param res The resulting path.
    * @note Time complexity: O(V), where V is the number of nodes in the graph.
    */
    void pathDFS(const int & source, std::vector<int> *res);



    /**
    * @brief Sets the visited status of all nodes in the graph.
    * @param visited The visited status to set for all nodes.
    * @note Time complexity: O(N), where N is the number of nodes in the graph.
    */
    void setNodesVisited(bool visited);



    /**
    * @brief Creates a minimum spanning tree (MST) graph using the provided source node.
    * @param source The index of the source node.
    * @param mstGraph The resulting MST graph.
    * @note Time complexity: O(V), where V is the number of nodes in the graph.
    */
    void createMSTGraph(const int & source, Graph *mstGraph);



    /**
    * @brief Implements our version of the Christofides Algorithm for the Traveling Salesman Problem (TSP).
    * @param path The minimum distance path based on the Christofides Algorithm.
    * @return The minimum distance using the Christofides Algorithm.
    * @note Time complexity: O(n^3) - cubic complexity.
    */
    double ourTryOnChristofidesAlgorithm(std::vector<int> &path);



    /**
    * @brief Computes the minimum weight matching for the given graph.
    * @param graph The graph to compute the matching on.
    * @return A vector of edges representing the minimum weight matching.
    * @note Time complexity: O(E log E), where E is the number of edges in the graph.
    */
    std::vector<Edge*> minimumWeightMatching(Graph &graph);



    /**
    * @brief Sets the indegree of each node based on the number of incoming edges.
    * @note Time complexity: O(N), where N is the number of nodes in the graph.
    */
    void setNodesIndegree();



    /**
    * @brief Checks if all nodes, except the one at the given index, have been visited.
    * @param index The index of the node to exclude from the check.
    * @return True if all nodes, except the one at the given index, have been visited; false otherwise.
    * @note Time complexity: O(N), where N is the number of nodes in the graph.
    */
    bool allVisitedExcept(int index);


private:
    std::vector<Node*> nodes;
};


#endif //PROJETO_2_GRAPH_H
