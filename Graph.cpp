#include "Graph.h"

void Graph::createRealworldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath) {

}

void Graph::createExtraGraphs(const std::string &filePath) {

}

void Graph::createToyGraph(const std::string& filePath) {

}

bool Graph::addNode(Node node) {
    if(findNode(node.getIndex()) != nullptr){
        return false;
    }
    this->nodes.push_back(new Node(node));
    return true;
}

bool Graph::addEdge(const int sourceIndex, const int destinyIndex, Edge edge) {
    Node* sourceNode = findNode(sourceIndex);
    Node* destinyNode = findNode(destinyIndex);

    if(sourceNode == nullptr || destinyNode == nullptr){
        return false;
    }

    sourceNode->addEdge(destinyNode, edge.getDistance());
    return true;
}

bool Graph::addBidirectionalEdge(const int sourceIndex, const int destinyIndex, Edge edge) {
    Node* sourceNode = findNode(sourceIndex);
    Node* destinyNode = findNode(destinyIndex);

    if(sourceNode == nullptr || destinyNode == nullptr){
        return false;
    }

    Edge* e1 = sourceNode->addEdge(destinyNode, edge.getDistance());
    Edge* e2 = sourceNode->addEdge(sourceNode, edge.getDistance());
    e1->setReverse(e2);
    e2->setReverse(e1);

    return true;
}

Node* Graph::findNode(int index) {
    for(auto &node: this->nodes){
        if(node->getIndex() == index){
            return node;
        }
    }
    return nullptr;
}