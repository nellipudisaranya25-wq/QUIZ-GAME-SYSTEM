#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <fstream>
#include <thread>
#include <atomic>
#include <chrono>
#include <conio.h>

#include "Question.h"
#include "Player.h"

using namespace std;

class Quiz
{
private:
    Question q[50];
    int totalQuestions;

public:
    Quiz();

    void loadQuestions();

    void startQuiz(Player &player);
};

#endif
