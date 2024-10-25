#include <iostream>
#include "CircularLinkedList.h"
#include "CircularDoublyLinkedList.h"
#include "Person.h"

using namespace std;

void showMenu() {
    cout << "====== MENU ======" << endl;
    cout << "1. Insertar persona" << endl;
    cout << "2. Eliminar persona por ID" << endl;
    cout << "3. Buscar persona por ID" << endl;
    cout << "4. Mostrar lista" << endl;
    cout << "5. Cambiar tipo de lista" << endl;
    cout << "6. Salir" << endl;
    cout << "==================" << endl;
    cout << "Seleccione una opción: ";
}

void showListTypeMenu() {
    cout << "====== TIPO DE LISTA ======" << endl;
    cout << "1. Circular Simplemente Enlazada" << endl;
    cout << "2. Circular Doblemente Enlazada" << endl;
    cout << "===========================" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    CircularSinglyLinkedList<Person> simpleList;
    CircularDoublyLinkedList<Person> doubleList;

    int option;
    int listType = 1;  // Por defecto, usar la lista circular simplemente enlazada
    string name, cedula;
    int age;

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                cout << "Ingrese nombre: ";
                cin >> name;
                cout << "Ingrese edad: ";
                cin >> age;
                cout << "Ingrese cédula: ";
                cin >> cedula;

                if (listType == 1) {
                    simpleList.insert(Person(name, age, cedula));
                } else {
                    doubleList.insert(Person(name, age, cedula));
                }
                break;

            case 2:
                cout << "Ingrese el ID interno de la persona a eliminar: ";
                cin >> cedula;

                if (listType == 1) {
                    simpleList.removeById(cedula);
                } else {
                    doubleList.removeById(cedula);
                }
                break;

            case 3:
                cout << "Ingrese el ID interno de la persona a buscar: ";
                cin >> cedula;

                if (listType == 1) {
                    simpleList.searchById(cedula);
                } else {
                    doubleList.searchById(cedula);
                }
                break;

            case 4:
                if (listType == 1) {
                    simpleList.display();
                } else {
                    doubleList.display();
                }
                break;

            case 5:
                showListTypeMenu();
                cin >> listType;

                if (listType != 1 && listType != 2) {
                    cout << "Opción no válida. Usando lista circular simplemente enlazada por defecto." << endl;
                    listType = 1;
                }
                break;

            case 6:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (option != 6);

    return 0;
}
