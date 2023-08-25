#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
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