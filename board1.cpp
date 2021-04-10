#include <iostream>
#include <vector>
using namespace std;////first board by shaylii and pardiis

vector<vector<char> > buildBoard1(int BOARD_SIZE) {

    vector<vector<char> > board1;



    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board1.push_back(vector<char>());
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board1[i].push_back(' ');
        }
    }

    return board1;
}

void printBoard1(vector<vector<char> >* board1, int BOARD_SIZE) {

    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << (*board1)[i][j] << "|";
        }
        cout << endl;
        cout << "  ";
        for (int y = 0; y < BOARD_SIZE; y++)
            cout << "--";
        cout << endl;
    }
}
int condition(int switch1, vector<vector<char> >* board1, int BOARD_SIZE) {

    if (switch1 == 1) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                if ((*board1)[i][j] == 'X') {
                    countToWin++;
                }
            }
            if (BOARD_SIZE < 6)
            {
                if (countToWin == BOARD_SIZE)
                {
                    cout << "Player 1 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }
            else if (BOARD_SIZE >= 6)
            {
                if (countToWin == 5)
                {
                    cout << "Player 1 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }

        }
    }
    else {
        for (int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                if ((*board1)[i][j] == 'O') {
                    countToWin++;
                }
            }
            if (BOARD_SIZE < 6)
            {
                if (countToWin == BOARD_SIZE)
                {
                    cout << "Player 2 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }
            else if (BOARD_SIZE >= 6)
            {
                if (countToWin == 5)
                {
                    cout << "Player 2 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }

        }
    }

    if (switch1 == 1) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                if ((*board1)[j][i] == 'X') {
                    countToWin++;
                }
            }
            if (BOARD_SIZE < 6)
            {
                if (countToWin == BOARD_SIZE)
                {
                    cout << "Player 1 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }
            else if (BOARD_SIZE >= 6)
            {
                if (countToWin == 5)
                {
                    cout << "Player 1 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }
        }
    }
    else {
        for (int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                if ((*board1)[j][i] == 'O') {
                    countToWin++;
                }
            }
            if (BOARD_SIZE < 6)
            {
                if (countToWin == BOARD_SIZE)
                {
                    cout << "Player 2 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }
            else if (BOARD_SIZE >= 6)
            {
                if (countToWin == 5)
                {
                    cout << "Player 2 has WON!" << endl;
                    printBoard1(board1, BOARD_SIZE);
                    exit(0);
                }
            }
        }
    }


    if (switch1 == 1) {
        int countToWin = 0;
        for (int i = 0, j = 0; i < BOARD_SIZE, j < BOARD_SIZE; i++, j++) {
            if ((*board1)[i][j] == 'X') {
                countToWin++;
            }
        }
        if (BOARD_SIZE < 6)
        {
            if (countToWin == BOARD_SIZE)
            {
                cout << "Player 1 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
        else if (BOARD_SIZE >= 6)
        {
            if (countToWin == 5)
            {
                cout << "Player 1 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
    }
    else {
        int countToWin = 0;
        for (int i = 0, j = 0; i < BOARD_SIZE, j < BOARD_SIZE; i++, j++) {
            if ((*board1)[i][j] == 'O') {
                countToWin++;
            }
        }
        if (BOARD_SIZE < 6)
        {
            if (countToWin == BOARD_SIZE)
            {
                cout << "Player 2 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
        else if (BOARD_SIZE >= 6)
        {
            if (countToWin == 5)
            {
                cout << "Player 2 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
    }


    if (switch1 == 1) {
        int countToWin = 0;
        for (int i = BOARD_SIZE - 1, j = BOARD_SIZE - 1; i >= 0, j >= 0; i--, j--) {
            if ((*board1)[i][j] == 'X') {
                countToWin++;
            }
        }
        if (BOARD_SIZE < 6)
        {
            if (countToWin == BOARD_SIZE)
            {
                cout << "Player 1 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
        else if (BOARD_SIZE >= 6)
        {
            if (countToWin == 5)
            {
                cout << "Player 1 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
    }
    else {
        int countToWin = 0;
        for (int i = BOARD_SIZE - 1, j = BOARD_SIZE - 1; i >= 0, j >= 0; i--, j--) {
            if ((*board1)[i][j] == 'O') {
                countToWin++;
            }
        }
        if (BOARD_SIZE < 6)
        {
            if (countToWin == BOARD_SIZE)
            {
                cout << "Player 2 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
        else if (BOARD_SIZE >= 6)
        {
            if (countToWin == 5)
            {
                cout << "Player 2 has WON!" << endl;
                printBoard1(board1, BOARD_SIZE);
                exit(0);
            }
        }
    }



    int countAllGone = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((*board1)[i][j] != ' ')

            {
                countAllGone++;
            }
        }
    }
    if (countAllGone == BOARD_SIZE * BOARD_SIZE) {
        cout << "NO WINNER!" << endl;
        exit(0);
    }

    return 0;
}

int turn(int switch1, vector<vector<char> >* board1, int BOARD_SIZE) {

    string input;
    bool validInput = false;
    int xInput = 0;
    int yInput = 0;

    if (switch1 == 1) {
        cout << "PLAYER 1 TURN!" << endl;////

        while (!validInput) {
            cout << "Type in Coordinates ex (1,2) to place an X on that spot!" << endl;
            cin >> input;

            xInput = (int)input[1] - 48;//char ro be adad convert konim:)
            yInput = (int)input[3] - 48;

            if ((*board1)[xInput - 1][yInput - 1] == 'O' ||
                (*board1)[xInput - 1][yInput - 1] == 'X' ||
                xInput > BOARD_SIZE ||
                yInput > BOARD_SIZE ||
                xInput < 1 ||
                yInput < 1) {
                cout << "Not Valid Input. Spot is already taken!" << endl;
            }
            else {
                validInput = true;
            }
        }
        //  if (bead == 1)
        (*board1)[xInput - 1][yInput - 1] = 'X';
        //  else
         //     (*board)[xInput - 1][yInput - 1] = 'o';
        condition(switch1, board1, BOARD_SIZE);

        switch1 = 0;
        return switch1;
    }
    else {
        cout << "PLAYER 2 TURN!" << endl;

        while (!validInput) {
            cout << "Type in Coordinates ex (1,2) to place an X on that spot!" << endl;
            cin >> input;

            xInput = (int)input[1] - 48;
            yInput = (int)input[3] - 48;

            if ((*board1)[xInput - 1][yInput - 1] == 'O' ||
                (*board1)[xInput - 1][yInput - 1] == 'X' ||
                xInput > BOARD_SIZE ||
                yInput > BOARD_SIZE ||
                xInput < 1 ||
                yInput < 1) {
                cout << "Not Valid Input. Choose Again!" << endl;
            }
            else {
                validInput = true;
            }

        }
        //if (bead == 1)
        (*board1)[xInput - 1][yInput - 1] = 'O';
        // else
          //   (*board)[xInput - 1][yInput - 1] = 'x';
        condition(switch1, board1, BOARD_SIZE);

        switch1 = 1;
        return switch1;
    }
}

int main() {

    int BOARD_SIZE = 0, bead, level;
    vector<vector<char> > board1;
    int continue1 = 0;
    int switch1 = 1;

    // cout << "Hello! Welcome to Tic Tac Toe!" << endl;//
    cout << "which one?[1]easy[2]medium[3]hard" << endl;
    cin >> level;
    if (level == 1)
        BOARD_SIZE = 3;
    else if (level == 2) {
        while (1) {
            cout << "please enter the board size.(3<size<7)" << endl;//
            cin >> BOARD_SIZE;
            if (BOARD_SIZE < 4 || BOARD_SIZE>6)
                cout << "errror." << endl;
            else
                break;
        }
    }
    else
    {
        while (1) {
            cout << "please enter the board size.(size>6)" << endl;//
            cin >> BOARD_SIZE;
            if (BOARD_SIZE < 7)
                cout << "error." << endl;
            else
                break;
        }
    }
    //cout << "which one do you want?enter a number. [1]'x'  [2]'o'";
    //cin >> bead;
    cout << "name of board:" << "tic tac toe" << endl;
    cout << "size of board:" << BOARD_SIZE << endl;
    if (BOARD_SIZE == 3)
        cout << "number of plots:3" << endl;
    else if (BOARD_SIZE == 4)
        cout << "number of plots:4" << endl;
    else if (BOARD_SIZE >= 5)
        cout << "number of plots:5" << endl;
    board1 = buildBoard1(BOARD_SIZE);
    while (continue1 == 0) {
        printBoard1(&board1, BOARD_SIZE);
        switch1 = turn(switch1, &board1, BOARD_SIZE);
        continue1 = condition(switch1, &board1, BOARD_SIZE);
    }
}