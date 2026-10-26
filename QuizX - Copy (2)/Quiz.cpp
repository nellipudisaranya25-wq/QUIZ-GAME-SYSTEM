#include "Quiz.h"

Quiz::Quiz()
{
    totalQuestions = 0;
}

// Read questions from file
void Quiz::loadQuestions()
{
    ifstream file("questions.txt");

    string question, A, B, C, D;
    char answer;

    while(getline(file, question))
    {
        getline(file, A);
        getline(file, B);
        getline(file, C);
        getline(file, D);

        file >> answer;
        file.ignore();

        q[totalQuestions].setQuestion(
            question, A, B, C, D, answer
        );

        totalQuestions++;
    }

    file.close();
}

// Start Quiz
void Quiz::startQuiz(Player &player)
{
    char userAnswer = '\0';
    int score = 0;

    for(int i = 0; i < totalQuestions; i++)
    {
        cout << "\n\n------------------------";
        cout << "\nQuestion " << i + 1 << endl;

        q[i].displayQuestion();

        cout << "\nYou have 1 minute for this question.\n";
        cout << "Enter Answer (A/B/C/D): " << flush;

        atomic<bool> timeUp(false);
        atomic<bool> answered(false);

        // Timer thread
        thread timerThread([&]()
        {
            for(int remaining = 60; remaining >= 0; remaining--)
            {
                if(answered)
                    return;

                cout << "\rTime Remaining: "
                     << remaining
                     << " seconds   "
                     << flush;

                if(remaining == 0)
                {
                    timeUp = true;
                    return;
                }

                this_thread::sleep_for(
                    chrono::seconds(1)
                );
            }
        });

        // Wait for keyboard input
        while(!timeUp)
        {
            if(_kbhit())
            {
                userAnswer = _getch();
                userAnswer = toupper(userAnswer);

                cout << "\nYou entered: "
                     << userAnswer << endl;

                answered = true;
                break;
            }

            this_thread::sleep_for(
                chrono::milliseconds(50)
            );
        }

        // Stop timer
        answered = true;

        if(timerThread.joinable())
            timerThread.join();

        // Time expired
        if(timeUp && !userAnswer)
        {
            cout << "\nTime's Up!" << endl;
            cout << "Moving to next question..." << endl;
            continue;
        }

        // Check answer
        if(q[i].checkAnswer(userAnswer))
        {
            cout << "Correct Answer!" << endl;
            score++;
        }
        else
        {
            cout << "Wrong Answer!" << endl;

            cout << "Correct Answer: "
                 << q[i].getCorrectAnswer()
                 << endl;
        }
    }

    player.setScore(score);
    player.setTotalQuestions(totalQuestions);

    cout << "\n========================";
    cout << "\nQuiz Completed!";
    cout << "\n========================" << endl;

    player.displayScore();
    player.saveResult();
}