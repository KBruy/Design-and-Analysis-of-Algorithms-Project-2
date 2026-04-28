#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "GraphList.h"
#include "GraphMatrix.h"
#include <vector>

class Dijkstra {
    public:
        static std::vector<int> runForList(const GraphList& graph, int startVertex);
        static std::vector<int> runForMatrix(const GraphMatrix& graph, int startVertex);

        static void printDistances(const std::vector<int>& distances, int startVertex);

};

#endif