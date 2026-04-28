#include "Research.h"
#include "GraphList.h"
#include "GraphMatrix.h"
#include "GraphGenerator.h"
#include "Dijkstra.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

void Research::run() {
    vector<int> verticesValues = {10,50,100,500,1000};
    vector<double> densities = {0.25, 0.50, 0.75, 1.00};

    int instanceCount = 100;

    ofstream file("results.csv");

    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku results.csv\n";
        return;
    }

    file << "representation,vertices,density,instances,average_time_ns\n";
    cout << "\nPomiar rozpoczety....\n";
    for (int vertices : verticesValues) {
        for (double density : densities) {
            cout << "V = " << vertices << ", gestosc = " << density * 100 << "%\n";

            long long listAverageTime = measureList(vertices, density, instanceCount);
            long long matrixAverageTime = measureMatrix(vertices, density, instanceCount);

            file << "list,"<<vertices<<","<<density<<","<<instanceCount<<","<<listAverageTime<<"\n";
            file << "matrix,"<<vertices<<","<<density<<","<<instanceCount<<","<<listAverageTime<<"\n";
        }
    }

    file.close();

    cout << "\nBadania zakonczone. Wyniki zapisano do pliku results.csv\n";
}


long long Research::measureList(int vertices, double density, int instanceCount) {
    long long totalTime = 0;
    int baseSeed = 12345;
    int startVertex = 0;

    for (int i = 0; i < instanceCount; i++) {
        int seed = baseSeed + vertices * 10000 + static_cast<int>(density * 1000) + i;

        GraphList graphList(vertices);
        GraphMatrix graphMatrix(vertices);

        GraphGenerator::generateRandomGraph(
            graphList,
            graphMatrix,
            vertices,
            density,
            seed
        );

        auto start = chrono::high_resolution_clock::now();

        vector<int> distances = Dijkstra::runForList(graphList, startVertex);

        auto end = chrono::high_resolution_clock::now();

        long long duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        totalTime += duration;
    }

    return totalTime / instanceCount;
}