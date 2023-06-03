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

void Graph::backtrackingRec(Node* node, unsigned int currentIndex, double currentDistance, std::vector<Node*> currentPath, double &minimumDistance, std::vector<Node*> &path) {
    node->setVisited(true);//Mark the node as visited

    currentPath[currentIndex - 1] = node;//Add the node to the current path

    if (currentIndex == getNumNodes()) {//If the current index is equal to the number of nodes, we have a possible path. Base case for the recursion
        node->setVisited(false);//Mark the node as not visited, allowing for a new path to be found

        //See if the last node connects to the first node
        Edge* finalEdge = nullptr;
        for (auto edge : node->getOutgoingEdges()) {
            if (edge->getDestinyNode()->getIndex() == 0) {
                finalEdge = edge;
                break;
            }
        }

        //If the last node connects to the first node, we have a possible path
        if(finalEdge != nullptr){
            currentDistance += finalEdge->getDistance();
            if (currentDistance < minimumDistance) {
                minimumDistance = currentDistance;
                path = currentPath;
            }
        }
        return;
    }

    //Try to find a path from the current node, if the distance is less than the minimum distance and the node hasn't been visited
    for(Edge* edge: node->getOutgoingEdges()){
        Node* nextNode = edge->getDestinyNode();

        if(!nextNode->isVisited() && currentDistance + edge->getDistance() < minimumDistance){
            backtrackingRec(nextNode, currentIndex + 1, currentDistance + edge->getDistance(), currentPath, minimumDistance, path);
        }
    }

    node->setVisited(false);
}

double Graph::TSPBacktracking(std::vector<Node*>& path) {
    std::vector<Node*> currentPath(getNumNodes());
    double minimumDist = INFINITY;

    setNodesVisited(false);

    backtrackingRec(nodes[0], 1, 0.0, currentPath, minimumDist, path);

    return minimumDist;
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

double Graph::triangularApproximationHeuristic(std::vector<Node *> &path) {
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

        path.push_back(orig);
    }
    path.push_back(primResult[0]);
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

void Graph::createMSTGraph(const int & source, Graph *mstGraph) {
    Node* v = findNode(source);
    for (auto e: v->getOutgoingEdges()){
        Node* w = e->getDestinyNode();
        Edge* path = w->getPath();
        if(path != nullptr){
            if(path->getSourceNode()->getIndex() == v->getIndex()){
                mstGraph->addBidirectionalEdge(path->getSourceNode()->getIndex(), path->getDestinyNode()->getIndex(), path->getDistance());
                createMSTGraph(w->getIndex(), mstGraph);
            }
        }
    }
}

double Graph::ourTryOnChristofidesAlgorithm(std::vector<int> &path) {
    Graph mstGraph;
    for(int i=0; i<nodes.size(); i++){
        mstGraph.addNode(i);
    }
    Graph oddNodesGraph;

    prim(); //Creates a MST by using Prim's algorithm

    createMSTGraph(0, &mstGraph); //Creates a MST graph by using the MST created by Prim's algorithm

    mstGraph.setNodesIndegree(); //Sets the indegree of each node

    std::vector<std::pair<std::pair<int, int>, double>> oddNodesEdges;
    for (auto v: mstGraph.getNodes()){//Creates a graph with the odd degree nodes of the MST
        if(v->getIndegree() % 2 != 0){
            oddNodesGraph.addNode(v->getIndex(), v->getLatitude(), v->getLongitude());
            Node* w = this->findNode(v->getIndex());
            for(Edge* edge: w->getOutgoingEdges()){
                Node* pointedTo = mstGraph.findNode(edge->getDestinyNode()->getIndex());
                if(pointedTo->getIndegree() % 2 != 0){
                    if(std::find(oddNodesEdges.begin(), oddNodesEdges.end(), std::make_pair(std::make_pair(edge->getDestinyNode()->getIndex(), v->getIndex()), edge->getDistance())) == oddNodesEdges.end())
                        oddNodesEdges.push_back(std::make_pair(std::make_pair(v->getIndex(), edge->getDestinyNode()->getIndex()), edge->getDistance()));
                }
            }
        }
    }

    for (auto e: oddNodesEdges){//Adds the edges to the oddNodesGraph
        oddNodesGraph.addBidirectionalEdge(e.first.first, e.first.second, e.second);
    }

    std::vector<Edge*> toAdd = minimumWeightMatching(oddNodesGraph);//Creates a minimum weight matching set of edges to add to the MST

    for (auto e: toAdd){//Adds the edges to the MST
        mstGraph.addBidirectionalEdge(e->getSourceNode()->getIndex(), e->getDestinyNode()->getIndex(), e->getDistance());
    }

    mstGraph.setNodesVisited(false);

    double distance = 0.0;
    Node* currentNode = mstGraph.findNode(0);
    currentNode->setVisited(true);

    for(int i = 0; i < mstGraph.getNodes().size(); i++){
        Edge* bestEdge = new Edge(INFINITY);
        path.push_back(currentNode->getIndex());
        for(Edge* edge : currentNode->getOutgoingEdges()){
            if(edge->getDistance() < bestEdge->getDistance() && !edge->getDestinyNode()->isVisited()){
                bestEdge = edge;
            }
        }
        if(bestEdge->getDistance() != INFINITY){
            distance += bestEdge->getDistance();
            currentNode = bestEdge->getDestinyNode();
            currentNode->setVisited(true);
        }
        else delete bestEdge;
    }

    if(path.size() == mstGraph.getNodes().size()){
        for(Edge* edge : currentNode->getOutgoingEdges()){
            if(edge->getDestinyNode()->getIndex() == 0){
                distance += edge->getDistance();
                path.push_back(0);
                return distance;
            }
        }
    }
/*
    for(int i=0; i<mstGraph.getNodes().size(); i++){
        Node* u = findNode(mstGraph.getNodes()[i]->getIndex());
        u->setVisited(mstGraph.getNodes()[i]->isVisited());
    }
    currentNode = findNode(currentNode->getIndex()); //Get current node of normal graph
    while(!allVisitedExcept(0)){
        for(auto &node:nodes){
            if(!node->isVisited() && node->getIndex() != 0){
                for(Edge* edge : currentNode->getOutgoingEdges()){
                    if(edge->getDestinyNode()->getIndex() == node->getIndex()){
                        distance += edge->getDistance();
                        path.push_back(node->getIndex());
                        break;
                    }
                }
                node->setVisited(true);
                currentNode = node;
            }
        }
    }
*/
    return distance;
}

std::vector<Edge*> Graph::minimumWeightMatching(Graph &graph) {
    graph.setNodesVisited(false);

    std::vector<Edge*> edges;

    for(auto v : graph.getNodes()) {
         for(auto e : v->getOutgoingEdges()) {
            if(std::find(edges.begin(), edges.end(), e->getReverseEdge()) == edges.end())
                edges.push_back(e);
        }
    }

    std::sort(edges.begin(), edges.end(), [](Edge* e1, Edge* e2) {
        return e1->getDistance() < e2->getDistance();
    });

    std::vector<Edge*> matching;

    for(auto e : edges) {
        if(!e->getSourceNode()->isVisited() && !e->getDestinyNode()->isVisited()) {
            matching.push_back(e);
            e->getSourceNode()->setVisited(true);
            e->getDestinyNode()->setVisited(true);
        }
    }

    return matching;
}

bool Graph::allVisitedExcept(int index){
    for (auto node:nodes){
        if (!node->isVisited() && node->getIndex() != index)
            return false;
    }
    return true;
}

void Graph::setNodesVisited(bool visited) {
    for(auto v : nodes) {
        v->setVisited(visited);
    }
}

void Graph::setNodesIndegree(){
    for(auto v:nodes){
        v->setIndegree(v->getIncomingEdges().size());
    }
}
