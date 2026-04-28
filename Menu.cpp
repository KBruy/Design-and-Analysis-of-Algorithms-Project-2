#include <iostream>
#include "Menu.h"
#include "GraphList.h"
#include "GraphMatrix.h"
#include "Dijkstra.h"


using namespace std;

void Menu::run() {
    int choice;

    do {
        showMainMenu();
        cin >> choice;

        switch (choice){
            case 1: {
    GraphList graphList(5);
    GraphMatrix graphMatrix(5);

    graphList.addEdge(0, 1, 4);
    graphList.addEdge(0, 2, 2);
    graphList.addEdge(1, 2, 1);
    graphList.addEdge(1, 3, 5);
    graphList.addEdge(2, 3, 8);
    graphList.addEdge(3, 4, 3);

    graphMatrix.addEdge(0, 1, 4);
    graphMatrix.addEdge(0, 2, 2);
    graphMatrix.addEdge(1, 2, 1);
    graphMatrix.addEdge(1, 3, 5);
    graphMatrix.addEdge(2, 3, 8);
    graphMatrix.addEdge(3, 4, 3);

    graphList.print();
    graphMatrix.print();

    int startVertex = 0;

    cout << "\nDijkstra dla listy sasiedztwa:\n";
    vector<int> distancesList = Dijkstra::runForList(graphList, startVertex);
    Dijkstra::printDistances(distancesList, startVertex);

    cout << "\nDijkstra dla macierzy sasiedztwa:\n";
    vector<int> distancesMatrix = Dijkstra::runForMatrix(graphMatrix, startVertex);
    Dijkstra::printDistances(distancesMatrix, startVertex);

    break;
}

            case 2:
            cout << "Badania efektywnosci\n";
            break;

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