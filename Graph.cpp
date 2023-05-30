#include "Graph.h"

int Graph::createRealworldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath) {
    //creating nodes
    std::ifstream nodesFile(nodesFilePath);

    if (!nodesFile.is_open()) {
        std::cerr << "Error opening the following nodesFile path: " << nodesFilePath << std::endl;
        return 1;
    }

    std::string index, latitude, longitude;

    std::string line;

    std::getline(nodesFile, line);

    while (std::getline(nodesFile, line)){
        std::istringstream iss(line);

        std::getline(iss, index, ',');
        std::getline(iss, longitude, ',');
        std::getline(iss, latitude, ',');

        this->nodes.push_back(new Node(std::stoi(index), std::stod(latitude), std::stod(longitude)));
    }
    nodesFile.close();

    //Creating edges
    std::ifstream edgesFile(edgesFilePath);

    if (!edgesFile.is_open()) {
        std::cerr << "Error opening the following edgesFile path: " << edgesFilePath << std::endl;
        return 1;
    }

    std::string sourceIndex, destinyIndex, distance;

    std::getline(edgesFile, line);

    while (std::getline(edgesFile, line)){
        std::istringstream iss(line);

        std::getline(iss, sourceIndex, ',');
        std::getline(iss, destinyIndex, ',');
        std::getline(iss, distance, ',');

        Node* sourceNode = findNode(std::stoi(sourceIndex));
        Node* destinyNode = findNode(std::stoi(destinyIndex));

        if(sourceNode == nullptr || destinyNode == nullptr){
            std::cerr << "Error finding the nodes with the following indexes: " << sourceIndex << " and " << destinyIndex << std::endl;
            return 1;
        }

        addBidirectionalEdge(sourceNode->getIndex(), destinyNode->getIndex(), Edge(sourceNode, destinyNode, std::stol(distance)));
    }

    edgesFile.close();

    return 0;
}

int Graph::createExtraGraphs(const std::string &edgesFilePath) {
    //Create the nodes
    std::filesystem::path filePath(edgesFilePath);
    std::string fileName = filePath.filename().string();

    std::size_t start = fileName.find_first_of("0123456789");
    std::size_t end = fileName.find_first_not_of("0123456789", start);

    std::string index = fileName.substr(start, end - start);
    std::cout << "Index: " <<index << std::endl;

    for(int i = 0; i < std::stoi(index); i++){
        this->nodes.push_back(new Node(i));
    }

    //Create the edges
    std::ifstream file(edgesFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening the following file path: " << filePath << std::endl;
        return 1;
    }

    std::string sourceIndex, destinyIndex, distance;

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)){
        std::istringstream iss(line);

        std::getline(iss, sourceIndex, ',');
        std::getline(iss, destinyIndex, ',');
        std::getline(iss, distance, ',');

        Node* sourceNode = findNode(std::stoi(sourceIndex));
        Node* destinyNode = findNode(std::stoi(destinyIndex));

        if(sourceNode == nullptr || destinyNode == nullptr){
            std::cerr << "Error finding the nodes with the following indexes: " << sourceIndex << " and " << destinyIndex << std::endl;
            return 1;
        }

        addBidirectionalEdge(sourceNode->getIndex(), destinyNode->getIndex(), Edge(sourceNode, destinyNode, std::stod(distance)));
    }

    return 0;
}

int Graph::createToyGraph(const std::string& filePath) {
    //Creating nodes
    std::string fileName;
    std::filesystem::path path(filePath);
    fileName = path.filename().string();
    int index = 0;

    if (fileName == "shipping.csv") {
        index = 13;
    } else if(fileName == "stadiums.csv") {
        index = 10;
    } else if (fileName == "tourism.csv") {
        index = 4;
    }

    for(int i = 0; i <= index; i++){
        this->nodes.push_back(new Node(i));
    }

    //Creating edges
    std::ifstream file(filePath);

    std::string sourceIndex, destinyIndex, distance;

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)){
        std::istringstream iss(line);

        std::getline(iss, sourceIndex, ',');
        std::getline(iss, destinyIndex, ',');
        std::getline(iss, distance, ',');

        Node* sourceNode = findNode(std::stoi(sourceIndex));
        Node* destinyNode = findNode(std::stoi(destinyIndex));

        if(sourceNode == nullptr || destinyNode == nullptr){
            std::cerr << "Error finding the nodes with the following indexes: " << sourceIndex << " and " << destinyIndex << std::endl;
            return 1;
        }

        addBidirectionalEdge(sourceNode->getIndex(), destinyNode->getIndex(), Edge(sourceNode, destinyNode, std::stod(distance)));
    }
    return 0;
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
    Edge* e2 = destinyNode->addEdge(sourceNode, edge.getDistance());
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

std::vector<Node*> Graph::getNodes() {
    return this->nodes;
}

int Graph::clearNodes() {
    for(Node* node: this->nodes){
        removeNode(node->getIndex());
    }
    return 0;
}

bool Graph::removeNode(int index) {
    Node* node = findNode(index);

    if(node == nullptr){
        return false;
    }

    std::vector<Edge*> outgoingEdges = node->getOutgoingEdges();
    for(Edge* edge: outgoingEdges){
        node->removeEdge(edge);
    }

    std::vector<Edge*> incomingEdges = node->getIncomingEdges();
    for(Edge* edge: incomingEdges){
        Node* sourceNode = edge->getSourceNode();
        sourceNode->removeEdge(edge);
    }

    auto itr = std::find(this->nodes.begin(), this->nodes.end(), node);
    if(itr != this->nodes.end()){
        this->nodes.erase(itr);
        delete node;
        return true;
    }
    return false;
}