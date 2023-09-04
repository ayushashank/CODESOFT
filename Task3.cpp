/*
TASK 3: TIC-TAC-TOE GAME
Problem Statement
Build a simple console-based Tic-Tac-Toe game that allows two players to play against each other.

Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.
*/

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

vector<vector<char>> board(3, vector<char>(3));

void display(char &player1, char &player2)
{
    cout << endl;
    cout << "Player 1: " << player1 << "  -  Player 2: " << player2 << endl
         << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

    cout << "     |     |     " << endl
         << endl;
}

bool win()
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return true;

    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return true;

    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return true;

    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return true;

    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return true;

    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return true;

    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    else
        return false;
}

bool draw()
{
    if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' &&
        board[1][1] != '5' && board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        return true;

    return false;
}

int main()
{
    char playAgain = 'Y';

    while (playAgain == 'Y')
    {
        Sleep(1500);   // To pause the execution for 1.5sec
        system("cls"); // To clear the terminal

        cout << "\t\tTIC-TAC-TOE" << endl;

        board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        int currPlayer = 1, pos;
        char player1, player2, mark;

        while (true)
        {
            cout << endl
                 << "Player 1, Enter your choice: (Enter 'X' for X and 'O' for O) ";
            cin >> player1;
            if (player1 == 'X')
            {
                player2 = 'O';
                break;
            }
            else if (player1 == 'O')
            {
                player2 = 'X';
                break;
            }
            else
            {
                cout << "Invalide choice!\nEnter again correctly!" << endl;
            }
        }

        while (true)
        {
            display(player1, player2);
            currPlayer = (currPlayer % 2 == 1) ? 1 : 2;

            cout << "Player " << currPlayer << ", Enter the position of your move: ";
            cin >> pos;

            mark = (currPlayer == 1) ? player1 : player2;

            if (pos == 1 && board[0][0] == '1')
                board[0][0] = mark;

            else if (pos == 2 && board[0][1] == '2')
                board[0][1] = mark;

            else if (pos == 3 && board[0][2] == '3')
                board[0][2] = mark;

            else if (pos == 4 && board[1][0] == '4')
                board[1][0] = mark;

            else if (pos == 5 && board[1][1] == '5')
                board[1][1] = mark;

            else if (pos == 6 && board[1][2] == '6')
                board[1][2] = mark;

            else if (pos == 7 && board[2][0] == '7')
                board[2][0] = mark;

            else if (pos == 8 && board[2][1] == '8')
                board[2][1] = mark;

            else if (pos == 9 && board[2][2] == '9')
                board[2][2] = mark;

            else
            {
                cout << "Invalid move, Enter again!" << endl;
                currPlayer--;
            }

            currPlayer++;

            if (win())
            {
                display(player1, player2);
                cout << "Game Ended! "
                     << "Winner is: Player " << (currPlayer - 1) << endl
                     << endl;
                break;
            }
            else if (draw())
            {
                display(player1, player2);
                cout << "Game drawn!" << endl
                     << endl;
                break;
            }
            else
            {
                cout << endl
                     << "Game is ongoing!" << endl
                     << endl;
            }
        }

        cout << "Do you want to play again? (Enter 'Y' for YES) ";
        cin >> playAgain;
    }

    cout << endl
         << endl
         << "Thank you for playing! Hope you liked it!" << endl
         << endl;

    return 0;
}