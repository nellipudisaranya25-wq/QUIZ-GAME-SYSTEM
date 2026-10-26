#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int id;

public:
    Person();

    void setPerson(string n, int i);

    void displayPerson();
};

#endif