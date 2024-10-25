#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    string id;      
    string cedula;    

    static int nextId; 

    Person() {}

    Person(string name, int age, string cedula) : name(name), age(age), cedula(cedula) {
        this->id = to_string(nextId++); 
    }

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Nombre: " << person.name << ", Edad: " << person.age 
           << ", Cédula: " << person.cedula << ", ID interno: " << person.id;
        return os;
    }

    bool operator==(const Person& other) const {
        return this->id == other.id; 
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }
};

int Person::nextId = 1;

#endif
