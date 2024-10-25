#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <iostream>
#include "Person.h"

using namespace std;

template <typename T>
class CircularDoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(T value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Persona añadida correctamente." << endl;
    }

    void removeById(string id) {
        if (isEmpty()) {
            cout << "La lista está vacía. No hay personas para eliminar." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data.id == id) {  
                if (current == head && head->next == head) {  
                    delete current;
                    head = nullptr;
                } else {
                    Node* prevNode = current->prev;
                    Node* nextNode = current->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;

                    if (current == head) {
                        head = nextNode;
                    }
                    delete current;
                }
                cout << "Persona con ID " << id << " eliminada correctamente." << endl;
                return;
            }
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
