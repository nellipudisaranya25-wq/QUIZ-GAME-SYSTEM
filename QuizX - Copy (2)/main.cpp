#include <iostream>
#include "Admin.h"
#include "Player.h"
#include "Quiz.h"

using namespace std;

int main()
{
    int choice;

    Admin admin;
    Player player;
    Quiz quiz;

    do
    {
        cout << "\n==================================" << endl;
        cout << "        QUIZ GAME SYSTEM" << endl;
        cout << "==================================" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Start Quiz" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
        // ================= ADMIN LOGIN =================
        case 1:

            if(admin.login())
            {
                int adminChoice;

                do
                {
                    cout << "\n==================================" << endl;
                    cout << "          ADMIN MENU" << endl;
                    cout << "==================================" << endl;

                    cout << "1. Add Question" << endl;
                    cout << "2. View Questions" << endl;
                    cout << "3. Edit Question" << endl;
                    cout << "4. Delete Question" << endl;
                    cout << "5. Logout" << endl;

                    cout << "Enter Choice: ";
                    cin >> adminChoice;

                    switch(adminChoice)
                    {
                    case 1:
                        admin.addQuestion();
                        break;

                    case 2:
                        admin.viewQuestions();
                        break;

                    case 3:
                        admin.editQuestion();
                        break;

                    case 4:
                        admin.deleteQuestion();
                        break;

                    case 5:
                        cout << "\nLogged Out Successfully!" << endl;
                        break;

                    default:
                        cout << "\nInvalid Choice!" << endl;
                    }

                } while(adminChoice != 5);
            }

            break;


        // ================= START QUIZ =================
        case 2:
        {
            string name;
            int id;

            cout << "\nEnter Player Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Player ID: ";
            cin >> id;

            player.setPerson(name, id);

            quiz.loadQuestions();

            quiz.startQuiz(player);

            break;
        }


        // ================= EXIT =================
        case 3:

            cout << "\nThank you for using Quiz Game System!" << endl;
            break;


        // ================= INVALID =================
        default:

            cout << "\nInvalid Choice!" << endl;
        }

    } while(choice != 3);

    return 0;
}