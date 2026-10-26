#include "Admin.h"
#include <cstdio>
// Constructor
Admin::Admin()
{
}

// Admin Login
bool Admin::login()
{
    string username, password;

    cout << "\n===== ADMIN LOGIN =====" << endl;

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    if(username == "admin" && password == "1234")
    {
        cout << "\nLogin Successful!\n";
        return true;
    }
    else
    {
        cout << "\nInvalid Username or Password.\n";
        return false;
    }
}

// Add Question
void Admin::addQuestion()
{
    ofstream file("questions.txt", ios::app);

    string question;
    string A, B, C, D;
    char answer;

    cin.ignore();

    cout << "\nEnter Question : ";
    getline(cin, question);

    cout << "Option A : ";
    getline(cin, A);

    cout << "Option B : ";
    getline(cin, B);

    cout << "Option C : ";
    getline(cin, C);

    cout << "Option D : ";
    getline(cin, D);

    cout << "Correct Answer (A/B/C/D) : ";
    cin >> answer;

    file << question << endl;
    file << A << endl;
    file << B << endl;
    file << C << endl;
    file << D << endl;
    file << answer << endl;

    file.close();

    cout << "\nQuestion Added Successfully!\n";
}
void Admin::viewQuestions()
{
    ifstream file("questions.txt");

    string line;

    cout << "\n===== ALL QUESTIONS =====\n";

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void Admin::deleteQuestion()
{
    ifstream file("questions.txt");

    if(!file)
    {
        cout << "\nUnable to open questions file!" << endl;
        return;
    }

    string question, A, B, C, D;
    char answer;

    int questionNumber;
    int currentNumber = 0;
    bool found = false;

    cout << "\n===== QUESTIONS =====" << endl;

    while(getline(file, question))
    {
        getline(file, A);
        getline(file, B);
        getline(file, C);
        getline(file, D);

        file >> answer;
        file.ignore();

        currentNumber++;

        cout << "\n" << currentNumber << ". "
             << question << endl;
    }

    file.close();

    if(currentNumber == 0)
    {
        cout << "\nNo questions available!" << endl;
        return;
    }

    cout << "\nEnter Question Number to Delete: ";
    cin >> questionNumber;

    if(questionNumber < 1 || questionNumber > currentNumber)
    {
        cout << "\nInvalid Question Number!" << endl;
        return;
    }

    ifstream inputFile("questions.txt");
    ofstream tempFile("temp.txt");

    currentNumber = 0;

    while(getline(inputFile, question))
    {
        getline(inputFile, A);
        getline(inputFile, B);
        getline(inputFile, C);
        getline(inputFile, D);

        inputFile >> answer;
        inputFile.ignore();

        currentNumber++;

        if(currentNumber == questionNumber)
        {
            found = true;
            continue;
        }

        tempFile << question << endl;
        tempFile << A << endl;
        tempFile << B << endl;
        tempFile << C << endl;
        tempFile << D << endl;
        tempFile << answer << endl;
    }

    inputFile.close();
    tempFile.close();

    remove("questions.txt");
    rename("temp.txt", "questions.txt");

    if(found)
    {
        cout << "\nQuestion deleted successfully!" << endl;
    }
}

void Admin::editQuestion()
{
    ifstream file("questions.txt");

    string question[50];
    string A[50], B[50], C[50], D[50];
    char answer[50];

    int total = 0;

    // Read questions
    while(getline(file, question[total]))
    {
        getline(file, A[total]);
        getline(file, B[total]);
        getline(file, C[total]);
        getline(file, D[total]);

        file >> answer[total];
        file.ignore();

        total++;
    }

    file.close();

    if(total == 0)
    {
        cout << "\nNo questions available!" << endl;
        return;
    }

    // Display questions
    cout << "\n===== QUESTIONS =====" << endl;

    for(int i = 0; i < total; i++)
    {
        cout << i + 1 << ". " << question[i] << endl;
    }

    int number;

    cout << "\nEnter Question Number to Edit: ";
    cin >> number;

    if(number < 1 || number > total)
    {
        cout << "\nInvalid Question Number!" << endl;
        return;
    }

    cin.ignore();

    cout << "\nEnter New Question: ";
    getline(cin, question[number - 1]);

    cout << "Enter Option A: ";
    getline(cin, A[number - 1]);

    cout << "Enter Option B: ";
    getline(cin, B[number - 1]);

    cout << "Enter Option C: ";
    getline(cin, C[number - 1]);

    cout << "Enter Option D: ";
    getline(cin, D[number - 1]);

    cout << "Enter Correct Answer (A/B/C/D): ";
    cin >> answer[number - 1];

    // Rewrite file
    ofstream newFile("questions.txt");

    for(int i = 0; i < total; i++)
    {
        newFile << question[i] << endl;
        newFile << A[i] << endl;
        newFile << B[i] << endl;
        newFile << C[i] << endl;
        newFile << D[i] << endl;
        newFile << answer[i] << endl;
    }

    newFile.close();

    cout << "\nQuestion edited successfully!" << endl;
}