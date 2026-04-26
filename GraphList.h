#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <vector>
#include <utility>

class GraphList {
    private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

    public:
        GraphList(int vertices);

        void addEdge(int from, int to, int weight);
        void print() const;

        int getVertices() const;
        const std::vector<std::pair<int, int>>& getNeighbors(int vertex) const;     
};

#endif