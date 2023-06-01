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
    for (auto & node : nodes){
        node->setPath(nullptr);
    }
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

unsigned long Graph::getNumNodes() const {
    return this->nodes.size();
}

void Graph::backtrackingRec(double **dists, unsigned int n, unsigned int curIndex, double curDist, unsigned int curPath[], double &minDist, unsigned int path[]) {
    if(curIndex == n) {
        curDist += dists[curPath[n - 1]][curPath[0]];
        if(curDist < minDist) {
            minDist = curDist;
            // Copy the current path to the path array
            for(unsigned int i = 0; i < n; i++) {
                path[i] = curPath[i];
            }
        }
        return;
    }

    // Try to add all possible vertices to the current path
    for(unsigned int i = 1; i < n; i++) { // The 0-th vertex is the initial vertex, so we skip it
        if(dists[curPath[curIndex - 1]][i] == -1) continue; // If there is no edge between the current vertex and the i-th vertex, skip it
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
                backtrackingRec(dists, n, curIndex + 1, curDist + dists[curPath[curIndex - 1]][curPath[curIndex]],
                                curPath, minDist, path);
            }
        }
    }
}

double Graph::TSPBacktracking(double **dists, unsigned int n, unsigned int path[]) {
    unsigned int curPath[n];
    double minDist = std::numeric_limits<double>::max();

    // Initialize the current path with node 0, by default
    curPath[0] = 0;

    // Call the recursive function starting with index 1 since node 0 is already in the path
    backtrackingRec(dists, n, 1, 0, curPath, minDist, path);
    return minDist;
}

std::vector<Node *> Graph::prim() {
    if (nodes.empty()) {
        return this->nodes;
    }

    // Reset auxiliary info
    for(auto v : nodes) {
        v->setDist(INFINITY);
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
        for(auto &e : v->getOutgoingEdges()) {
            Node* w = e->getDestinyNode();
            if (!w->isVisited()) {
                auto oldDist = w->getDist();
                if(e->getDistance() < oldDist) {
                    w->setDist(e->getDistance());
                    w->setPath(e);
                    if (oldDist == INFINITY) {
                        q.insert(w);
                    }
                    else {
                        q.decreaseKey(w);
                    }
                }
            }
        }
    }

    return this->nodes;
}

double Graph::triangularApproximationHeuristic(){
    std::cout << "Triangular Approximation Heuristic:\n";
    double approxDist = 0.0;
    std::vector<Node *> primResult = prim();
    std::vector<int> res;
    pathDFS(0,&res);
    int vectorSize = res.size();
    for (int i=0; i<vectorSize; i++){
        bool flag = false;
        Node* orig = primResult[res[i]];
        Node* dest = primResult[res[(i+1)%vectorSize]];
        for(auto e:orig->getOutgoingEdges()){
            if (e->getDestinyNode()->getIndex() == dest->getIndex()){
                approxDist += e->getDistance();
                flag = true;
                break;
            }
        }
        if(!flag)
            approxDist += haversine(orig->getLatitude(), orig->getLongitude(), dest->getLatitude(), dest->getLongitude());

        std::cout << orig->getIndex() << "->";
    }
    std::cout << primResult[0]->getIndex() << '\n';
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

void Graph::pathDFS(const int & source, std::vector<int> *res) {
    Node* v = findNode(source);
    res->push_back(v->getIndex());
    for (auto e: v->getOutgoingEdges()){
        Node* w = e->getDestinyNode();
        Edge* path = w->getPath();
        if(path != nullptr){
            if(path->getSourceNode()->getIndex() == v->getIndex()){
                pathDFS(w->getIndex(),res);
            }
        }
    }
}
