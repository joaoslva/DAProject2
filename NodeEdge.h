#ifndef PROJETO_2_NODEEDGE_H
#define PROJETO_2_NODEEDGE_H

#include <vector>
#include <string>

class Edge;

class Node{
public:
    Node(int index, double latitude, double longitude); //used for real-world graph
    Node(int index); //used for extra graphs

    Edge* addEdge(Node* destinyNode, double distance);
    bool removeEdge(int destID);
    void deleteEdge(Edge* edge);
    void removeOutgoingEdges();

    int getIndex();
    std::vector<Edge*> getOutgoingEdges();
    std::vector<Edge*> getIncomingEdges();

private:
    int index;
    std::string label; //only used in the tourism toy graph
    double latitude; //only used for real-world graphs
    double longitude; //only used for real-world graphs

    std::vector<Edge*> outgoingEdges;
    std::vector<Edge*> incomingEdges;

    Node* parentNode = nullptr;
};


class Edge{
public:
    Edge(Node* sourceNode, Node* destinyNode, double distance);

    Node* getSourceNode();
    Node* getDestinyNode();
    double getDistance();

    void setReverse(Edge* edge);

private:
    Node* sourceNode;
    Node* destinyNode;

    double distance;

    Edge* reverseEdge;
};

#endif //PROJETO_2_NODEEDGE_H
