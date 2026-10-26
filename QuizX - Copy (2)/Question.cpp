#include "Question.h"

// Constructor
Question::Question()
{
    question = "";
    optionA = "";
    optionB = "";
    optionC = "";
    optionD = "";
    correctAnswer = 'A';
}

// Set question details
void Question::setQuestion(string q, string a, string b,
                           string c, string d, char ans)
{
    question = q;
    optionA = a;
    optionB = b;
    optionC = c;
    optionD = d;
    correctAnswer = ans;
}

// Display question
void Question::displayQuestion()
{
    cout << "\nQuestion: " << question << endl;
    cout << "A. " << optionA << endl;
    cout << "B. " << optionB << endl;
    cout << "C. " << optionC << endl;
    cout << "D. " << optionD << endl;
}

// Check answer
bool Question::checkAnswer(char userAnswer)
{
    if (toupper(userAnswer) == toupper(correctAnswer))
        return true;
    else
        return false;
}
char Question::getCorrectAnswer()
{
    return correctAnswer;
}