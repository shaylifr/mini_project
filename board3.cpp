#include <iostream>
#include <iomanip>

#define BOARD_SIZE 21
using namespace std;
char board[][100] =
{
                      {"                                                          "},
                      {"1****************************2***************************3"},
                      {"*                            |                           *"},
                      {"*                            |                           *"},
                      {"*        4*******************5*******************6       *"},
                      {"*        *                   |                   *       *"},
                      {"*        *                   |                   *       *"},
                      {"*        *                   |                   *       *"},
                      {"*        *        7**********8**********9        *       *"},
                      {"*        *        *                     *        *       *"},
                      {"*        *        *                     *        *       *"},
                      {"*        *        *                     *        *       *"},
                      {"a--------b--------c                     d--------e-------f"},
                      {"*        *        *                     *        *       *"},
                      {"*        *        *                     *        *       *"},
                      {"*        *        *                     *        *       *"},
                      {"*        *        g*********************h        *       *"},
                      {"*        *     o                          o      *       *"},
                      {"*        *   o                               o   *       *"},
                      {"*        * o                                    o*       *"},
                      {"*        i***************************************j       *"},
                      {"*     o                                             o    *"},
                      {"*   o                                                 o  *"},
                      {"* o                                                     o*"},
                      {"k********************************************************l"}

};

int boardRow = sizeof(board) / sizeof(*board);
int boardCol = sizeof(*board) / sizeof(**board);
int BOARD[BOARD_SIZE] = { 0 };
int Winner = 0;

void updateBoard()
{

    system("cls");

    //Part 2
    int X = 10;
    int x = 0;
    for (int i = 0; i < boardRow; i++)
    {
        for (int j = 0; j < boardCol; j++)
        {
            if ((board[i][j] >= '1' && board[i][j] <= '9') || (board[i][j] >= 'a' && board[i][j] <= 'n'))
            {

                if (BOARD[x] != 0)
                {
                    cout << (BOARD[x] == 1 ? "X" : "O");
                    x++;

                    if (board[i][j] >= 'a' && board[i][j] <= 'n')
                    {
                        X++;
                    }

                    continue;
                }
                x++;
            }


            if (board[i][j] >= 'a' && board[i][j] <= 'n')
            {
                //check the array
                cout << X++;
                j++;
            }
            else
            {
                cout << board[i][j];
            }
        }

        cout << endl;
    }

    cout << endl;

}//end of function




bool checkForWinning()
{

    int* p = BOARD;

    if (p[0] != 0 && p[0] == p[1] && p[1] == p[2])
    {
        Winner = p[1];
        return true;
    }

    if (p[3] != 0 && p[3] == p[4] && p[3] == p[5])
    {
        Winner = p[3];
        return true;
    }


    if (p[6] != 0 && p[6] == p[7] && p[6] == p[8])
    {
        Winner = p[6];
        return true;
    }

    if (p[9] != 0 && p[9] == p[10] && p[9] == p[11])
    {
        Winner = p[9];
        return true;
    }

    if (p[12] != 0 && p[12] == p[13] && p[12] == p[14])
    {
        Winner = p[12];
        return true;
    }

    if (p[15] != 0 && p[15] == p[17] && p[15] == p[19])
    {
        Winner = p[15];
        return true;
    }

    if (p[16] != 0 && p[16] == p[18] && p[16] == p[20])
    {
        Winner = p[16];
        return true;
    }


    if (p[0] != 0 && p[0] == p[9] && p[0] == p[19])
    {
        Winner = p[0];
        return true;
    }


    if (p[2] != 0 && p[2] == p[14] && p[2] == p[20])
    {
        Winner = p[2];
        return true;
    }


    if (p[1] != 0 && p[1] == p[4] && p[1] == p[7])
    {
        Winner = p[1];
        return true;
    }


    if (p[3] != 0 && p[3] == p[10] && p[3] == p[17])
    {
        Winner = p[3];
        return true;
    }


    if (p[5] != 0 && p[5] == p[13] && p[5] == p[18])
    {
        Winner = p[5];
        return true;
    }

    if (p[6] != 0 && p[6] == p[11] && p[6] == p[15])
    {
        Winner = p[6];
        return true;
    }


    if (p[8] != 0 && p[8] == p[12] && p[8] == p[16])
    {
        Winner = p[8];
        return true;
    }


    return false;
}//End of check for Winner function



bool setPlace(int place, int p)
{
    if (BOARD[place - 1] != 0)
        return false;

    BOARD[place - 1] = p;
    return true;
}

int main()
{

    bool loop = true;
    bool firstP = true;

    int ans;

    while (loop)
    {
        updateBoard();
        cout << endl;

        cout << "Player 1 = X" << "\t";
        cout << "Player 2 = O" << endl;

        cout << "---Current Player: " << (firstP ? "Player 1" : "Player 2") << "---" << endl;

        cout << "Enter \'0\' to exit" << endl;

        cout << "Choose the place you wanna go: ";
        do
        {
            if (cin >> ans)
            {
                if (ans >= 0 && ans <= 21)
                {
                    if (ans == 0)
                    {
                        loop = false;
                        break;
                    }

                    if (setPlace(ans, (firstP ? 1 : 2)))
                        break;
                }
            }

            cin.clear();
            cout << "Wrong Answer! try again: ";
        } while (true);


        if (checkForWinning())
            loop = false;

        firstP = !firstP;
    }

    if (Winner)
    {
        cout << "------------Winner is " << (Winner == 1 ? "Player 1" : "Player 2") << "------------" << endl;
    }

    return 0;
}