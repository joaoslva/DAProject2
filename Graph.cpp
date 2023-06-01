#include <xmath.h>
#include "Graph.h"
#include "MutablePriorityQueue.h"

int Graph::createRealWorldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath) {
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

        addNode(std::stoi(index), std::stod(latitude), std::stod(longitude));
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

        addBidirectionalEdge(sourceNode->getIndex(), destinyNode->getIndex(), std::stol(distance));
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

        addBidirectionalEdge(sourceNode->getIndex(), destinyNode->getIndex(), std::stod(distance));
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

        addBidirectionalEdge(sourceNode->getIndex(), destinyNode->getIndex(), std::stod(distance));
    }
    return 0;
}

bool Graph::addNode(const int &nodeIndex, double latitude, double longitude) {
    if (findNode(nodeIndex) != nullptr)
        return false;
    nodes.push_back(new Node(nodeIndex, latitude, longitude));
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourceIndex, const int &destinyIndex, double distance) {
    Node* sourceNode = findNode(sourceIndex);
    Node* destinyNode = findNode(destinyIndex);

    if(sourceNode == nullptr || destinyNode == nullptr){
        return false;
    }

    Edge* e1 = sourceNode->addEdge(destinyNode, distance);
    Edge* e2 = destinyNode->addEdge(sourceNode, distance);
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

void Graph::clearNodes() {
    for (auto it = nodes.begin(); it != nodes.end();) {
        auto v = *it;
        v->removeOutgoingEdges();
        for (auto u : nodes) {
            u->removeEdge(v->getIndex());
        }
        it = nodes.erase(it);
        delete v;
    }
}

Graph::~Graph() {
    clearNodes();
}

void tspBTRec(const unsigned int **dists, unsigned int n, unsigned int curIndex, unsigned int curDist, unsigned int curPath[], unsigned int &minDist, unsigned int path[]) {
    if(curIndex == n) {
        // add the distance back to the initial node
        curDist += dists[curPath[n - 1]][curPath[0]];
        if(curDist < minDist) {
            minDist = curDist;
            // Copy the current state to the array storing the best state found so far
            for(unsigned int i = 0; i < n; i++) {
                path[i] = curPath[i];
            }
        }
        return;
    }
    // Try to move to the i-th vertex if the total distance does not exceed the best distance found and the vertex is not yet visited in curPath
    for(unsigned int i = 1; i < n; i++) { // i starts at 1 and not 0 since it is assumed that node 0 is the initial node so it will not be in the middle of the path
        if(curDist + dists[curPath[curIndex - 1]][i] < minDist) {
            bool isNewVertex = true;
            for(unsigned int j = 1; j < curIndex; j++) {
                if(curPath[j] == i) {
                    isNewVertex = false;
                    break;
                }
            }
            if(isNewVertex) {
                curPath[curIndex] = i;
                tspBTRec(dists,n,curIndex+1,curDist + dists[curPath[curIndex - 1]][curPath[curIndex]],curPath,minDist,path);
            }
        }
    }
}

unsigned int tspBT(const unsigned int **dists, unsigned int n, unsigned int path[]) {
    unsigned int curPath[10000]; // static memory allocation is faster :)
    unsigned int minDist = std::numeric_limits<unsigned int>::max();

    // Assumes path starts at node 0 ...
    curPath[0] = 0;
    // ... so in the first recursive call curIndex starts at 1 rather than 0
    tspBTRec(dists, n, 1, 0, curPath, minDist, path);
    return minDist;
}

std::vector<Node *> Graph::prim() {
    std::vector<Node *> preOrder; // Stores the pre-order traversal
    if (nodes.empty()) {
        return this->nodes;
    }

    // Reset auxiliary info
    for(auto v : nodes) {
        v->setDist(INF);
        v->setPath(nullptr);
        v->setVisited(false);
    }

    // start with an arbitrary vertex
    Node* s = nodes.front();
    s->setDist(0);

    // initialize priority queue
    MutablePriorityQueue<Node> q;
    q.insert(s);
    // process vertices in the priority queue
    while( ! q.empty() ) {
        auto v = q.extractMin();
        v->setVisited(true);
        preOrder.push_back(v); // Add the visited vertex to the pre-order traversal
        for(auto &e : v->getOutgoingEdges()) {
            Node* w = e->getDestinyNode();
            if (!w->isVisited()) {
                auto oldDist = w->getDist();
                if(e->getDistance() < oldDist) {
                    w->setDist(e->getDistance());
                    w->setPath(e);
                    if (oldDist == INF) {
                        q.insert(w);
                    }
                    else {
                        q.decreaseKey(w);
                    }
                }
            }
        }
    }

    return preOrder;
}

double Graph::triangularApproximationHeuristic(){
    double approxDist = 0.0;
    std::vector<Node *> primResult = prim();
    int vectorSize = primResult.size();
    for (int i=0; i<vectorSize; i++){
        Node* orig = primResult[i];
        Node* dest = primResult[(i+1)%vectorSize];
        approxDist += haversine(orig->getLatitude(), orig->getLongitude(), dest->getLatitude(), dest->getLongitude());
    }
    return approxDist;
}

double Graph::toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {
    double kEarthRadius = 6371000.0;
    // Convert latitude and longitude to radians
    double phi1 = toRadians(lat1);
    double phi2 = toRadians(lat2);
    double deltaPhi = toRadians(lat2 - lat1);
    double deltaLambda = toRadians(lon2 - lon1);

    // Haversine formula
    double a = std::sin(deltaPhi / 2) * std::sin(deltaPhi / 2) +
               std::cos(phi1) * std::cos(phi2) *
               std::sin(deltaLambda / 2) * std::sin(deltaLambda / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    double distance = kEarthRadius * c;

    return distance;
}
