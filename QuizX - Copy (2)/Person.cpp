#include "Person.h"

// Constructor
Person::Person()
{
    name = "";
    id = 0;
}

// Set details
void Person::setPerson(string n, int i)
{
    name = n;
    id = i;
}

// Display details
void Person::displayPerson()
{
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
}