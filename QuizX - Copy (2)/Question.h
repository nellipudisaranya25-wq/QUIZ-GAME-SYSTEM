#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
using namespace std;

class Question
{
private:
    string question;
    string optionA, optionB, optionC, optionD;
    char correctAnswer;

public:
    Question();
    void setQuestion(string q, string a, string b,                        
                     string c, string d, char ans);

    void displayQuestion();

    bool checkAnswer(char userAnswer);

    char getCorrectAnswer();
};

#endif