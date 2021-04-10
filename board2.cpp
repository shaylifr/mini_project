#include <iostream>
#include <vector>
#include<time.h>
#include<windows.h>
using namespace std;////zamine aval

vector<char>  buildBoard() {

    vector<char> board;



    for (int i = 0; i < 16; i++)
    {
        {
            board.push_back(' ');
        }
    }

    return board;
}


void printBoard(vector<char>* board) {
    cout << endl << endl;
    cout << "13(" << (*board)[13] << ")---------14(" << (*board)[14] << ")--------15(" << (*board)[15] << ")" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |   10(" << (*board)[10] << ")--11(" << (*board)[11] << ")--12(" << (*board)[12] << ")    |" << endl
        << "   |      |             |     |" << endl
        << " 6(" << (*board)[6] << ")---7(" << (*board)[7] << ")          8(" << (*board)[8] << ")--9(" << (*board)[9] << ")" << endl
        << "   |      |             |     |" << endl
        << "   |    3(" << (*board)[3] << ")---4(" << (*board)[4] << ")---5(" << (*board)[5] << ")    |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << " 0(" << (*board)[0] << ")----------1(" << (*board)[1] << ")---------2(" << (*board)[2] << ")" << endl;

}
int condition(int switch2, vector<char>* board) {


    if (switch2 == 1) {
        if ((*board)[0] == 'X' && (*board)[1] == 'X' && (*board)[2] == 'X' || (*board)[3] == 'X' && (*board)[4] == 'X' && (*board)[5] == 'X' || (*board)[10] == 'X' && (*board)[11] == 'X' && (*board)[12] == 'X' || (*board)[13] == 'X' && (*board)[14] == 'X' && (*board)[15] == 'X' || (*board)[0] == 'X' && (*board)[6] == 'X' && (*board)[13] == 'X' || (*board)[3] == 'X' && (*board)[7] == 'X' && (*board)[10] == 'X' || (*board)[5] == 'X' && (*board)[8] == 'X' && (*board)[12] == 'X' || (*board)[2] == 'X' && (*board)[9] == 'X' && (*board)[15] == 'X') {

            cout << "Player 1 has WON!" << endl;
            printBoard(board);
            exit(0);
        }
    }
    else {
        if ((*board)[0] == 'O' && (*board)[1] == 'O' && (*board)[2] == 'O' || (*board)[3] == 'O' && (*board)[4] == 'O' && (*board)[5] == 'O' || (*board)[10] == 'O' && (*board)[11] == 'O' && (*board)[12] == 'O' || (*board)[13] == 'O' && (*board)[14] == 'O' && (*board)[15] == 'O' || (*board)[0] == 'O' && (*board)[6] == 'O' && (*board)[13] == 'O' || (*board)[3] == 'O' && (*board)[7] == 'O' && (*board)[10] == 'O' || (*board)[5] == 'O' && (*board)[8] == 'O' && (*board)[12] == 'O' || (*board)[2] == 'O' && (*board)[9] == 'O' && (*board)[15] == 'O') {

            cout << "Player 2 has WON!" << endl;
            printBoard((board));
            exit(0);
        }
    }



    // Check if there is no winner

    int countAllGone = 0;
    for (int i = 0; i < 16; i++) {

        if ((*board)[i] != ' ')

        {
            countAllGone++;
        }
    }
    if (countAllGone == 16) {
        cout << "NO WINNER!" << endl;
        exit(0);
    }

    return 0;
}
int turn(int switch2, vector<char>* board) {

    int Input;
    bool validInput = false;

    if (switch2 == 1) {
        Sleep(3000);
        system("cls");
        cout << "PLAYER 1 TURN!" << endl;////

        while (!validInput) {
            cout << "Type the number of your position:)" << endl;
            cin >> Input;

            if ((*board)[Input] == 'O' ||
                (*board)[Input] == 'X' ||
                Input > 15 ||
                Input < 0) {
                cout << "Not Valid Input. Spot is already taken!" << endl;
            }
            else {
                validInput = true;
            }
        }
        //  if (bead == 1)
        (*board)[Input] = 'X';
        //  else
         //     (*board)[xInput - 1][yInput - 1] = 'o';
        condition(switch2, board);

        switch2 = 0;
        return switch2;
    }
    else {
        Sleep(3000);
        system("cls");
        cout << "PLAYER 2 TURN!" << endl;

        while (!validInput) {
            cout << "Type the number of your position:)" << endl;
            cin >> Input;

            if ((*board)[Input] == 'O' ||
                (*board)[Input] == 'X' ||
                Input > 15 ||
                Input < 0) {
                cout << "Not Valid Input. Choose Again!" << endl;
            }
            else {
                validInput = true;
            }

        }
        //if (bead == 1)
        (*board)[Input] = 'O';
        // else
          //   (*board)[xInput - 1][yInput - 1] = 'x';
        condition(switch2, board);
        switch2 = 1;
        return switch2;
    }
}






int main() {

    int bead;
    int Continue1 = 0;
    int switch2 = 1;

    cout << "name of board:six men's morris" << endl;
    cout << "size of board:3" << endl;
    cout << "number of plots:3" << endl;
    vector<char> board;
    board = buildBoard();
    while (Continue1 == 0) {
        printBoard((&board));
        switch2 = turn(switch2, (&board));
        Continue1 = condition(switch2, &board);
    }



}