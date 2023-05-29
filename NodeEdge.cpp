#include "NodeEdge.h"
//Node stuff
Node::Node(int index, double latitude, double longitude) {
    this->index = index;
    this->latitude = latitude;
    this->longitude = longitude;
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

void Node::removeEdge(Edge *edge) {
    auto itr = this->outgoingEdges.begin();
    while (itr != this->outgoingEdges.end()){
        Edge* e = *itr;
        Node* n = e->getDestinyNode();
        if(n->getIndex() == edge->getDestinyNode()->getIndex()){
            itr = this->outgoingEdges.erase(itr);
            deleteEdge(e);
        }
        else{
            itr++;
        }
    }
}

int Node::getIndex() {
    return this->index;
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