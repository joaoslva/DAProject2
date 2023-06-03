#ifndef PROJETO_2_NODEEDGE_H
#define PROJETO_2_NODEEDGE_H

#include <vector>
#include <string>

class Edge;

class Node{
public:
    /**
    * @brief Constructs a Node object with the given index, latitude, and longitude.
    * @param index The index of the node.
    * @param latitude The latitude of the node.
    * @param longitude The longitude of the node.
    * @note Time complexity: O(1)
    */
    Node(int index, double latitude, double longitude); //used for real-world graph
    
    
    /**
    * @brief Constructs a Node object with the given index and initializes latitude, longitude, and label to 0 and an empty string, respectively.
    * @param index The index of the node.
    * @note Time complexity: O(1)
    */
    Node(int index); //used for extra graphs

    
    /**
    * @brief Adds an edge from the current node to the destination node with the given distance.
    * @param destinyNode Pointer to the destination node.
    * @param distance The distance of the edge.
    * @return Pointer to the created edge.
    * @note Time complexity: O(1)
    */
    Edge* addEdge(Node* destinyNode, double distance);
    
    
    /**
    * @brief Removes an outgoing edge with the specified destination ID.
    * @param destID The destination ID of the edge to be removed.
    * @return True if an edge was successfully removed, false otherwise.
    * @note Time complexity: O(K), where K is the number of outgoing edges from the node.
    */
    bool removeEdge(int destID);
    
    
    /**
    * @brief Deletes the given edge from the incoming edges of the destination node.
    * @param edge Pointer to the edge to be deleted.
    * @note Time complexity: O(K), where K is the number of incoming edges of the destination node.
    */
    void deleteEdge(Edge* edge);
    
    
    /**
    * @brief Removes all outgoing edges from the node.
    * @note Time complexity: O(K), where K is the number of outgoing edges from the node.
    */
    void removeOutgoingEdges();


    /**
    * @brief Returns the index of the node.
    * @return The index of the node.
    * @note Time complexity: O(1)
    */
    int getIndex();
    
    
    /**
    * @brief Returns a vector of outgoing edges from the node.
    * @return Vector of outgoing edges.
    * @note Time complexity: O(1)
    */
    std::vector<Edge*> getOutgoingEdges();
    
    
    /**
    * @brief Returns a vector of incoming edges to the node.
    * @return Vector of incoming edges.
    * @note Time complexity: O(1)
    */
    std::vector<Edge*> getIncomingEdges();



    /**
    * @brief Sets the distance value of the node.
    * @param dist The distance value to set.
    * @note Time complexity: O(1).
    */
    void setDist(double dist);



    /**
    * @brief Sets the visited status of the node.
    * @param visited The visited status to set.
    * @note Time complexity: O(1).
    */
    void setVisited(bool visited);



    /**
    * @brief Sets the path of the node.
    * @param path The path to set.
    * @note Time complexity: O(1).
    */
    void setPath(Edge *path);



    /**
    * @brief Retrieves the distance value of the node.
    * @return The distance value of the node.
    * @note Time complexity: O(1).
    */
    double getDist() const;



    /**
    * @brief Checks if the node has been visited.
    * @return True if the node has been visited; false otherwise.
    * @note Time complexity: O(1).
    */
    bool isVisited() const;



    /**
    * @brief Retrieves the latitude of the node.
    * @return The latitude of the node.
    * @note Time complexity: O(1).
    */
    double getLatitude() const;



    /**
    * @brief Retrieves the longitude of the node.
    * @return The longitude of the node.
    * @note Time complexity: O(1).
    */
    double getLongitude() const;



    /**
    * @brief Retrieves the path of the node.
    * @return The path of the node.
    * @note Time complexity: O(1).
    */
    Edge *getPath() const;



    /**
    * @brief Retrieves the indegree of the node.
    * @return The indegree of the node.
    * @note Time complexity: O(1).
    */
    unsigned int getIndegree() const;



    /**
    * @brief Sets the indegree of the node.
    * @param indegree The indegree to set.
    * @note Time complexity: O(1).
    */
    void setIndegree(unsigned int indegree);



    /**
    * @brief Compares two nodes based on their distance values.
    * @param vertex The node to compare with.
    * @return True if the distance value of this node is less than the distance value of the other node; false otherwise.
    * @note Time complexity: O(1).
    */
    bool operator<(Node & vertex) const; // // required by MutablePriorityQueue

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS


private:
    int index;
    std::string label; //only used in the tourism toy graph
    double latitude; //only used for real-world graphs
    double longitude; //only used for real-world graphs

    double dist = 0;
    bool visited = false;
    Edge *path = nullptr;
    unsigned int indegree;

    std::vector<Edge*> outgoingEdges;
    std::vector<Edge*> incomingEdges;

    Node* parentNode = nullptr;
};


class Edge{
public:
    /**
    * @brief Constructs an Edge object with the given source node, destination node, and distance.
    * @param sourceNode Pointer to the source node.
    * @param destinyNode Pointer to the destination node.
    * @param distance The distance of the edge.
    * @note Time complexity: O(1)
    */
    Edge(Node* sourceNode, Node* destinyNode, double distance);

    Edge(double distance);
    /**
    * @brief Returns the source node of the edge.
    * @return Pointer to the source node.
    * @note Time complexity: O(1)
    */
    Node* getSourceNode();
    
    
    /**
    * @brief Returns the destination node of the edge.
    * @return Pointer to the destination node.
    * @note Time complexity: O(1)
    */
    Node* getDestinyNode();
    
    
    /**
    * @brief Returns the distance of the edge.
    * @return The distance of the edge.
    * @note Time complexity: O(1)
    */
    double getDistance();


    /**
    * @brief Sets the reverse edge for the current edge.
    * @param edge Pointer to the reverse edge.
    * @note Time complexity: O(1)
    */
    void setReverse(Edge* edge);



    /**
    * @brief Retrieves the reverse edge of the current edge.
    * @return The reverse edge of the current edge.
    * @note Time complexity: O(1).
    */
    Edge* getReverseEdge();

private:
    Node* sourceNode;
    Node* destinyNode;

    double distance;

    Edge* reverseEdge;
};

#endif //PROJETO_2_NODEEDGE_H
