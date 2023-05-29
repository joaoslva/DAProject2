#ifndef PROJETO_2_CVSREADER_H
#define PROJETO_2_CVSREADER_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "../Graph.h"
#include "../NodeEdge.h"

class CvsReader {
    static std::vector<Node> readNodes(const std::string &filepath);
    static std::vector<Edge> readEdges(const std::string &filepath);
    static Graph toyGraphReader(int index);
};


#endif //PROJETO_2_CVSREADER_H
