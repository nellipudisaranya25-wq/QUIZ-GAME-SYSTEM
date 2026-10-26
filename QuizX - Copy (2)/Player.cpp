#include "Player.h"
#include <fstream>

Player::Player()
{
    score = 0;
    totalQuestions = 0;
}

void Player::setScore(int s)
{
    score = s;
}

void Player::setTotalQuestions(int total)
{
    totalQuestions = total;
}

int Player::getScore()
{
    return score;
}

void Player::displayScore()
{
    cout << "\n===== RESULT =====" << endl;
    cout << "Player Name : " << name << endl;
    cout << "Player ID   : " << id << endl;
    cout << "Score       : " << score << "/" << totalQuestions << endl;

    if(totalQuestions > 0)
    {
        float percentage = (score * 100.0f) / totalQuestions;
        cout << "Percentage  : " << percentage << "%" << endl;
    }
}

void Player::saveResult()
{
    ofstream file("results.txt", ios::app);

    float percentage = 0;

    if(totalQuestions > 0)
    {
        percentage = (score * 100.0f) / totalQuestions;
    }

    file << "\n==============================\n";
    file << "          QUIZ RESULT\n";
    file << "==============================\n";

    file << "Player Name : " << name << endl;
    file << "Player ID   : " << id << endl;
    file << "Score       : " << score
         << "/" << totalQuestions << endl;
    file << "Percentage  : " << percentage << "%" << endl;

    file << "==============================\n";

    file.close();
}