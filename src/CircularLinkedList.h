#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include "Person.h"

using namespace std;

template <typename T>
class CircularSinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    CircularSinglyLinkedList() : head(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(T value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Persona añadida correctamente." << endl;
    }

    void removeById(string id) {
        if (isEmpty()) {
            cout << "La lista está vacía. No hay personas para eliminar." << endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        if (head->next == head && head->data.id == id) {
            delete head;
            head = nullptr;
            cout << "Persona con ID " << id << " eliminada correctamente." << endl;
            return;
        }

        do {
            if (current->data.id == id) {
                if (current == head) {

                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                    delete current;
                } else {
    
                    previous->next = current->next;
                    delete current;
                }
                cout << "Persona con ID " << id << " eliminada correctamente." << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        cout << "No se encontró ninguna persona con el ID " << id << "." << endl;
    }

    void searchById(string id) {
        if (isEmpty()) {
            cout << "La lista está vacía. No hay personas para buscar." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data.id == id) {
                cout << "Persona encontrada: " << current->data << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "No se encontró ninguna persona con el ID " << id << "." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "La lista está vacía." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << endl;
            current = current->next;
        } while (current != head);
    }
};

#endif