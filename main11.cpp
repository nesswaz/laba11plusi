#include <iostream>
#include "h11.h"
#ifdef _WIN64
#include <windows.h>
#endif
int main() {
    using namespace std;
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    int choice;
    do {
        cout << "\nСписок задач:\n";
        cout << "1. ListWork68;" << endl;
        cout << "2. ListWork42" << endl;
        cout << "3. ListWork43" << endl;
        cout << "4. ListWork46" << endl;
        cout << "5. 7" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                ListWork68();
                break;
            }
            case 2: {
                ListWork42();
                break;
            }
            case 3: {
                ListWork43();
                break;
            }
            case 4: {
                ListWork46();
                break;
            }
            case 5: {
                number7();
                break;
            }
            case 0: {
                cout << "Выход из программы\n";
                break;
            }
            default:
                cout << "Введено неверный пункт\n";
        }
    } 
    while (choice != 0);
    return 0;
}