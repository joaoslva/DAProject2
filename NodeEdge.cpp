#include "NodeEdge.h"
//Node stuff
Node::Node(int index, double latitude, double longitude) {
    this->index = index;
    this->latitude = latitude;
    this->longitude = longitude;
    this->label = "";
}

Node::Node(int index) {
    this->index = index;
    this->latitude = 0;
    this->longitude = 0;
    this->label = "";
}

Edge* Node::addEdge(Node *destinyNode, double distance) {
    Edge* edge = new Edge(this, destinyNode, distance);
    outgoingEdges.push_back(edge);
    destinyNode->incomingEdges.push_back(edge);
    return edge;
}

void Node::deleteEdge(Edge *edge) {
    Node* destinyNode = edge->getDestinyNode();
    auto itr = destinyNode->incomingEdges.begin();
    while (itr != destinyNode->incomingEdges.end()){
        if((*itr)->getSourceNode()->getIndex() == this->index){
            itr = destinyNode->incomingEdges.erase(itr);
        }
        else{
            itr++;
        }
    }
    delete edge;
}

bool Node::removeEdge(int destID) {
    bool removedEdge = false;
    auto it = outgoingEdges.begin();
    while (it != outgoingEdges.end()) {
        Edge *edge = *it;
        Node *dest = edge->getDestinyNode();
        if (dest->getIndex() == destID) {
            it = outgoingEdges.erase(it);
            deleteEdge(edge);
            removedEdge = true;
        }
        else {
            it++;
        }
    }
    return removedEdge;
}

int Node::getIndex() {
    return this->index;
}

std::vector<Edge*> Node::getOutgoingEdges() {
    return this->outgoingEdges;
}

std::vector<Edge*> Node::getIncomingEdges() {
    return this->incomingEdges;
}

void Node::removeOutgoingEdges() {
    auto it = outgoingEdges.begin();
    while (it != outgoingEdges.end()) {
        Edge *edge = *it;
        it = outgoingEdges.erase(it);
        deleteEdge(edge);
    }
}

//Edge stuff
Edge::Edge(Node *sourceNode, Node *destinyNode, double distance) {
    this->sourceNode = sourceNode;
    this->destinyNode = destinyNode;
    this->distance = distance;
}

void Edge::setReverse(Edge *edge) {
    this->reverseEdge = edge;
}

Node* Edge::getSourceNode() {
    return this->sourceNode;
}

Node* Edge::getDestinyNode() {
    return this->destinyNode;
}

double Edge::getDistance() {
    return this->distance;
}