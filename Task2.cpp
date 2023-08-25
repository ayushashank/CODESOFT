/*
Problem Statement
Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. Allow the user to input two numbers and choose an operation to perform.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << endl;

    float num1, num2;

    cout << "Enter operand 1: ";
    cin >> num1;
    cout << "Enter operand 2: ";
    cin >> num2;

    char op;

    cout << endl
         << "Enter operator: +, -, *, / : ";
    cin >> op;

    switch (op)
    {

    // Addition
    case '+':
        cout << endl
             << num1 << " + " << num2 << " = " << num1 + num2;
        break;

    // Subtraction
    case '-':
        cout << endl
             << num1 << " - " << num2 << " = " << num1 - num2;
        break;

    // Multiplication
    case '*':
        cout << endl
             << num1 << " * " << num2 << " = " << num1 * num2;
        break;

    // Division
    case '/':
        if (num2 == 0)
        {
            cout << endl
                 << "Division with 0 is not possible";
        }
        else
        {
            cout << endl
                 << num1 << " / " << num2 << " = " << num1 / num2;
        }
        break;

    // Incorrect operator
    default:
        cout << endl
             << "Error! the operator entered is incorrect.";
        break;
    }

    cout << endl
         << endl;
    return 0;
}
