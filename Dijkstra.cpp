#include "Dijkstra.h"
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

vector<int> Dijkstra::runForList(const GraphList& graph, int startVertex) {
    int vertices = graph.getVertices();

    vector<int> distances(vertices, INT_MAX);

    // para: (odleglosc, wierzcholek)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    distances[startVertex] = 0;
    queue.push({0, startVertex});

    while (!queue.empty()) {
        int currentDistance = queue.top().first;
        int currentVertex = queue.top().second;
        queue.pop();

        // Pomijamy stare, nieaktualne wpisy z kolejki
        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        const vector<pair<int, int>>& neighbors = graph.getNeighbors(currentVertex);

        for (auto edge : neighbors) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distances[currentVertex] != INT_MAX &&
                distances[currentVertex] + weight < distances[neighbor]) {

                distances[neighbor] = distances[currentVertex] + weight;
                queue.push({distances[neighbor], neighbor});
            }
        }
    }

    return distances;
}
