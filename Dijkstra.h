#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "GraphList.h"
#include "GraphMatrix.h"
#include <vector>

struct DijkstraResult {
    std::vector<int> distances;
    std::vector<int> previous;
};

class Dijkstra {
public:
    static DijkstraResult runForList(const GraphList& graph, int startVertex);
    static DijkstraResult runForMatrix(const GraphMatrix& graph, int startVertex);

    static void printDistances(const DijkstraResult& result, int startVertex);
    static void printPath(const DijkstraResult& result, int startVertex, int endVertex);
};

#endif