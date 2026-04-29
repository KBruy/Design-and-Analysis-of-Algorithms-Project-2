#include "Dijkstra.h"
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

DijkstraResult Dijkstra::runForList(const GraphList& graph, int startVertex) {
    int vertices = graph.getVertices();

    vector<int> distances(vertices, INT_MAX);
    vector<int> previous(vertices, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    distances[startVertex] = 0;
    queue.push({0, startVertex});

    while (!queue.empty()) {
        int currentDistance = queue.top().first;
        int currentVertex = queue.top().second;
        queue.pop();

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
                previous[neighbor] = currentVertex;

                queue.push({distances[neighbor], neighbor});
            }
        }
    }

    return {distances, previous};
}

DijkstraResult Dijkstra::runForMatrix(const GraphMatrix& graph, int startVertex) {
    int vertices = graph.getVertices();

    vector<int> distances(vertices, INT_MAX);
    vector<int> previous(vertices, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    distances[startVertex] = 0;
    queue.push({0, startVertex});

    while (!queue.empty()) {
        int currentDistance = queue.top().first;
        int currentVertex = queue.top().second;
        queue.pop();

        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        for (int neighbor = 0; neighbor < vertices; neighbor++) {
            int weight = graph.getWeight(currentVertex, neighbor);

            if (weight > 0) {
                if (distances[currentVertex] != INT_MAX &&
                    distances[currentVertex] + weight < distances[neighbor]) {

                    distances[neighbor] = distances[currentVertex] + weight;
                    previous[neighbor] = currentVertex;

                    queue.push({distances[neighbor], neighbor});
                }
            }
        }
    }

    return {distances, previous};
}

void Dijkstra::printDistances(const DijkstraResult& result, int startVertex) {
    cout << "\nNajkrotsze odleglosci od wierzcholka " << startVertex << ":\n";

    for (int i = 0; i < static_cast<int>(result.distances.size()); i++) {
        cout << startVertex << " -> " << i << ": ";

        if (result.distances[i] == INT_MAX) {
            cout << "brak sciezki";
        } else {
            cout << result.distances[i];
        }

        cout << endl;
    }
}

void Dijkstra::printPath(const DijkstraResult& result, int startVertex, int endVertex) {
    if (endVertex < 0 || endVertex >= static_cast<int>(result.distances.size())) {
        cout << "Niepoprawny wierzcholek koncowy.\n";
        return;
    }

    if (result.distances[endVertex] == INT_MAX) {
        cout << "Brak sciezki z " << startVertex << " do " << endVertex << ".\n";
        return;
    }

    vector<int> path;

    int current = endVertex;

    while (current != -1) {
        path.push_back(current);

        if (current == startVertex) {
            break;
        }

        current = result.previous[current];
    }

    reverse(path.begin(), path.end());

    cout << "Sciezka " << startVertex << " -> " << endVertex << ": ";

    for (int i = 0; i < static_cast<int>(path.size()); i++) {
        cout << path[i];

        if (i != static_cast<int>(path.size()) - 1) {
            cout << " -> ";
        }
    }

    cout << ", koszt = " << result.distances[endVertex] << endl;
}