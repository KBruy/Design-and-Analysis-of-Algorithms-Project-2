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
            int vertices = 6;
            double density = 0.5;
            int seed = 12345;
            int startVertex = 0;
            int endVertex = vertices - 1;

            GraphList graphList(vertices);
            GraphMatrix graphMatrix(vertices);

            GraphGenerator::generateRandomGraph(
                graphList,
                graphMatrix,
                vertices,
                density,
                seed
            );

            cout << "\nDemonstracja algorytmu Dijkstry\n";
            cout << "Liczba wierzcholkow: " << vertices << endl;
            cout << "Gestosc: " << density * 100 << "%\n";
            cout << "Seed: " << seed << endl;
            cout << "Wierzcholek startowy: " << startVertex << endl;
            cout << "Przykladowy wierzcholek koncowy: " << endVertex << endl;

            graphList.print();
            graphMatrix.print();

            cout << "\nDijkstra dla listy sasiedztwa:\n";
            DijkstraResult resultList = Dijkstra::runForList(graphList, startVertex);
            Dijkstra::printDistances(resultList, startVertex);
            Dijkstra::printPath(resultList, startVertex, endVertex);

            cout << "\nDijkstra dla macierzy sasiedztwa:\n";
            DijkstraResult resultMatrix = Dijkstra::runForMatrix(graphMatrix, startVertex);
            Dijkstra::printDistances(resultMatrix, startVertex);
            Dijkstra::printPath(resultMatrix, startVertex, endVertex);

            if (resultList.distances == resultMatrix.distances) {
                cout << "\nWyniki dla listy i macierzy sa zgodne.\n";
            } else {
                cout << "\nUWAGA: Wyniki dla listy i macierzy sa rozne.\n";
            }

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