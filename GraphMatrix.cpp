#include "GraphMatrix.h"
#include <iostream>

using namespace std;

GraphMatrix::GraphMatrix(int vertices) {
    this->vertices = vertices;

    matrix.resize(vertices, vector<int>(vertices, 0));
}

void GraphMatrix::addEdge(int from, int to, int weight) {
    if (from < 0 || from >= vertices || to < 0 || to >= vertices) {
        return;
    }

    if (weight <= 0) {
        return;
    }

    //graf nieskierowany, wiec wpisujemy wage w obie strony
    matrix[from][to] = weight;
    matrix[to][from] = weight;
}

    void GraphMatrix::print() const {
        cout << "\nMacierz sasiedztwa:\n";

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout <<endl;
        }
    }

    int GraphMatrix::getVertices() const {
        return vertices;
    }

    int GraphMatrix::getWeight(int from, int to) const {
    if (from < 0 || from >= vertices || to < 0 || to >= vertices) {
        return 0;
    }

    return matrix[from][to];
}