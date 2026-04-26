#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <vector>

class GraphMatrix {
    private:
        int vertices;
        std::vector<std::vector<int>> matrix;

    public:
        GraphMatrix(int vertices);

        void addEdge(int from, int to, int weight);
        void print() const;

        int getVertices() const;
        int getWeight(int from, int to) const;

};

#endif