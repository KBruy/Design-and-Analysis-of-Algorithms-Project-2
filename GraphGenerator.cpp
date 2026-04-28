#include "GraphGenerator.h"
#include <vector>
#include <utility>
#include <random>
#include <algorithm>

using namespace std;

void GraphGenerator::generateRandomGraph(
    GraphList& graphList,
    GraphMatrix& graphMatrix,
    int vertices,
    double density,
    int seed
) {
    vector<pair<int, int>> allEdges;

    // Tworzenie wszystkich mozliwych krawedzi grafu nieskierowanego
    // Dla grafu nieskierowanego wystarczy i<j zeby nie dublowac krawedzi

    for (int i=0; i<vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            allEdges.push_back({i, j});
        }
    }

    mt19937 generator(seed);

    //mieszamy liste wszystkich mozliwych krawedzi,
    //zeby potem dodawac je w losowej kolejnosci

    shuffle(allEdges.begin(), allEdges.end(), generator);
    int maxEdges = vertices * (vertices - 1) / 2;
    int targetEdges = static_cast<int>(maxEdges * density);

    //graf spojny musi miec conajmniej vertices - 1 krawedzi
    if (targetEdges < vertices - 1) {
        targetEdges = vertices - 1;
    }

    uniform_int_distribution<int> weightDistribution(1, 100);

    int addedEdges = 0;

    //najpierw dodajnie prostej sciezki 0-1-2...
    //zeby zagwarantowac spojnosc grafu

    for (int i =0; i < vertices - 1; i++) {
        int weight = weightDistribution(generator);

        graphList.addEdge(i, i+1, weight);
        graphMatrix.addEdge(i, i+1, weight);

        addedEdges++;
    }

    //dodanie kolejnych losowych krawdzi az do wymaganej gestosci
    for (auto edge : allEdges) {
        if (addedEdges >= targetEdges) {
            break;
        }

        int from = edge.first;
        int to = edge.second;

        // pomijanie krawedzi ktore dodalismy juz w sciezce spojnosci
        if (to == from + 1) {
            continue;
        }

        int weight = weightDistribution(generator);

        graphList.addEdge(from, to, weight);
        graphMatrix.addEdge(from, to, weight);

        addedEdges++;
    }

}