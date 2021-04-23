#include "field1.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
static bool timerStarts;
using namespace std;
static bool halghe;
static char convertPlayerChar(int n)
{
    if (n == 1)
        return 'X';

    if (n == 2)
        return 'O';

    return ' ';
}

Field1::Field1()
{
    BOARD_SIZE = 9;
    for (int i = 0; i < BOARD_SIZE; i++)
        board.push_back(0);


}

void Field1::updateBoard()
{
    system("color F");
    cout << endl << endl;
    cout << " 7(" << convertPlayerChar(board[6]) << ")----------8(" << convertPlayerChar(board[7]) << ")---------9(" << convertPlayerChar(board[8]) << ")" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << " 4(" << convertPlayerChar(board[3]) << ")----------5(" << convertPlayerChar(board[4]) << ")---------6(" << convertPlayerChar(board[5]) << ")" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << " 1(" << convertPlayerChar(board[0]) << ")----------2(" << convertPlayerChar(board[1]) << ")---------3(" << convertPlayerChar(board[2]) << ")" << endl;
}

bool Field1::checkForWining(int n)
{
    if ((board)[0] == n && (board)[1] == n && (board)[2] == n || (board)[3] == n && (board)[4] == n && (board)[5] == n || (board)[6] == n && (board)[7] == n && (board)[8] == n || (board)[0] == n && (board)[3] == n && (board)[6] == n || (board)[1] == n && (board)[4] == n && (board)[7] == n || (board)[2] == n && (board)[5] == n && (board)[8] == n || (board)[0] == n && (board)[8] == n && (board)[4] == n || (board)[2] == n && (board)[4] == n && (board)[6] == n) {


        return true;
    }


    return false;
}


bool Field1::setPlace(int place, int p)
{
    if (board[place - 1] != 0)
        return false;

    board[place - 1] = p;
    return true;
}



bool Field1::checkForDraw()
{

    int countAllGone = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {

        if ((board)[i] != 0)
        {
            countAllGone++;
        }
    }

    if (countAllGone == BOARD_SIZE) {
        return true;
    }

    else
        return false;

}

int Field1::getInput(int p)
{

    int Input;
    bool validInput = false;


    // cout << "PLAYER 1 TURN!" << endl;////

    while (!validInput) {
        cout << "Type the number of your position:)" << endl;
        cin >> Input;

        if (Input == 0)
            break;

        if ((board)[Input - 1] != 0 ||
            Input > BOARD_SIZE ||
            Input < 0) {
            cout << "Not Valid Input. Spot is already taken!" << endl;
        }
        else {
            validInput = true;
        }
    }


    if (Input != 0)
        setPlace(Input, p);

    return Input;
}
