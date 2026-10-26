#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

class Admin : public Person
{
public:
    Admin();

    bool login();

    void addQuestion();

    void viewQuestions();

    void deleteQuestion();

    void editQuestion();
};

#endif