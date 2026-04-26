#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::run() {
    int choice;

    do {
        showMainMenu();
        cin >> choice;

        switch (choice){
            case 1:
            cout << "Demonstracja algorytmu Dijkstry\n";
            break;

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