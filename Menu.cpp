#include <iostream>
#include "Menu.h"
#include "GraphList.h"
#include "GraphMatrix.h"
#include "Dijkstra.h"
#include "GraphGenerator.h"
#include "Research.h"

using namespace std;

void Menu::run() {
    int choice;

    do {
        showMainMenu();
        cin >> choice;

        switch (choice){
            case 1: {
                cout<<"dupa";
        int vertices = 6;
        double density = 0.5;
        int seed = 12345;
        int startVertex = 0;

        GraphList graphList(vertices);
        GraphMatrix graphMatrix(vertices);

        GraphGenerator::generateRandomGraph(
            graphList,
            graphMatrix,
            vertices,
            density,
            seed
        );

        graphList.print();
        graphMatrix.print();

        cout << "\nDijkstra dla listy sasiedztwa:\n";
        vector<int> distancesList = Dijkstra::runForList(graphList, startVertex);
        Dijkstra::printDistances(distancesList, startVertex);

        cout << "\nDijkstra dla macierzy sasiedztwa:\n";
        vector<int> distancesMatrix = Dijkstra::runForMatrix(graphMatrix, startVertex);
        Dijkstra::printDistances(distancesMatrix, startVertex);

        break;
    }

            case 2: {
                Research research;
                research.run();
                break;
            }

            case 0:
            cout << "Koniec programu\n";
            break;

            default:
            cout << "Niepoprawna opcja\n";
            break;
        }
    }   while (choice != 0);
}

void Menu::showMainMenu(){
    cout << "\n==== Projekt 2 - Grafy ====\n";
    cout << "1. Demonstracja algorytmu Dijkstry\n";
    cout << "2. Uruchom badania efektywnosci\n";
    cout << "0. Zakoncz program\n";
    cout << "Wybor: ";
}