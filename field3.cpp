#include "field3.h"

using namespace std;

const char BOARD[][100] = {
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




Field3::Field3()
{
    BOARD_SIZE = 21;
    boardRow = sizeof(BOARD) / sizeof(*BOARD);
    boardCol = sizeof(*BOARD) / sizeof(**BOARD);


    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board.push_back(0);
    }

}

void Field3::updateBoard()
{

    int X = 10;
    int x = 0;
    for (int i = 0; i < boardRow; i++)
    {
        for (int j = 0; j < boardCol; j++)
        {
            if ((BOARD[i][j] >= '1' && BOARD[i][j] <= '9') || (BOARD[i][j] >= 'a' && BOARD[i][j] <= 'n'))
            {

                if (board[x] != 0)
                {
                    cout << (board[x] == 1 ? "X" : "O");
                    x++;

                    if (BOARD[i][j] >= 'a' && BOARD[i][j] <= 'n')
                    {
                        X++;
                    }

                    continue;
                }
                x++;
            }


            if (BOARD[i][j] >= 'a' && BOARD[i][j] <= 'n')
            {
                //check the array
                cout << X++;
                j++;
            }
            else
            {
                cout << BOARD[i][j];
            }
        }

        cout << endl;
    }

    cout << endl;
}

bool Field3::checkForWining(int n)
{
    vector<int>& p = board;

    if (p[0] != 0 && p[0] == p[1] && p[1] == p[2])
    {
        return true;
    }

    if (p[0] != 0 && p[0] == p[3] && p[0] == p[6])
    {
        return true;
    }

    if (p[3] != 0 && p[3] == p[4] && p[3] == p[5])
    {
        return true;
    }


    if (p[6] != 0 && p[6] == p[7] && p[6] == p[8])
    {
        return true;
    }

    if (p[9] != 0 && p[9] == p[10] && p[9] == p[11])
    {
        return true;
    }

    if (p[12] != 0 && p[12] == p[13] && p[12] == p[14])
    {
        return true;
    }

    if (p[15] != 0 && p[15] == p[17] && p[15] == p[19])
    {
        return true;
    }

    if (p[16] != 0 && p[16] == p[18] && p[16] == p[20])
    {
        return true;
    }


    if (p[0] != 0 && p[0] == p[9] && p[0] == p[19])
    {
        return true;
    }


    if (p[2] != 0 && p[2] == p[14] && p[2] == p[20])
    {
        return true;
    }


    if (p[1] != 0 && p[1] == p[4] && p[1] == p[7])
    {
        return true;
    }


    if (p[3] != 0 && p[3] == p[10] && p[3] == p[17])
    {
        return true;
    }


    if (p[5] != 0 && p[5] == p[13] && p[5] == p[18])
    {
        return true;
    }

    if (p[6] != 0 && p[6] == p[11] && p[6] == p[15])
    {
        return true;
    }


    if (p[8] != 0 && p[8] == p[12] && p[8] == p[16])
    {
        return true;
    }


    return false;
}


bool Field3::setPlace(int place, int p)
{
    if (board[place - 1] != 0)
        return false;

    board[place - 1] = p;
    return true;
}



bool Field3::checkForDraw()
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


    return false;

}

int Field3::getInput(int p)
{

    int ans;

    cout << "Choose the place you wanna go: " << endl;
    do
    {
        if (cin >> ans)
        {
            if (ans >= 0 && ans <= BOARD_SIZE)
            {
                if (ans == 0)
                    break;

                if (setPlace(ans, p))
                    break;
            }
        }

        cin.clear();
        cout << "Wrong Answer! try again: ";
    } while (true);



    return ans;
}


