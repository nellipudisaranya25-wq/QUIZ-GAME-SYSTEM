#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Person.h"

using namespace std;

class Player : public Person
{
private:
    int score;
    int totalQuestions;

public:
    Player();

    void setScore(int s);
    void setTotalQuestions(int total);

    int getScore();

    void displayScore();
    void saveResult();
};

#endif