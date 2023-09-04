/*
TASK 1: NUMBER GUESSING GAME
Problem Statement
Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the guess is too high or too low until the user guesses the correct number.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    system("cls");
    srand(time(0)); // To clear the terminal
    // The number will be between 0 and 100
    int num = rand() % 100;

    int n;

    while (true)
    {
        cout << endl
             << "Guess the number: ";
        cin >> n;

        if (n > num)
            cout << "The number you guessed is greater. Guess Again!" << endl;

        else if (n < num)
            cout << "The number you guessed is smaller. Guess Again!" << endl;

        else
        {
            cout << "Congrats! You've guessed correctly!" << endl
                 << endl;
            break;
        }
    }

    return 0;
}