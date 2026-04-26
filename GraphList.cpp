#include "GraphList.h"
#include <iostream>

using namespace std;

GraphList::GraphList(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void GraphList::addEdge(int from, int to, int weight) {
    if (from < 0 || from >= vertices || to < 0 || to >= vertices) {
        return;
    }

    if (weight <= 0) {
        return;
    }

    //graf nieskierowany -> dodajmeny krawędź w obie strony
    adjacencyList[from].push_back({to, weight});
    adjacencyList[to].push_back({from, weight});
}

void GraphList::print() const {
    cout << "\nLista sasiedztwa:\n";

    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";

        for (auto edge : adjacencyList[i]) {
            cout << "(" <<edge.first << ", waga: "<< edge.second<< ") ";
        }

        cout <<endl;
    }
}

int GraphList::getVertices() const {
    return vertices;
}

const vector<pair<int, int>>& GraphList::getNeighbors(int vertex) const {
    return adjacencyList[vertex];
}


