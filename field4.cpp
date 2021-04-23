#include "field4.h"

using namespace std;

const char BOARD[][100] = {
                      {"                                                                            "},
                      {"           1                                                                "},
                      {"           *    *                                                           "},
                      {"           *       *                                                        "},
                      {"           *         2---------------------------3-------------------------4"},
                      {"           *         * *                         *                        * "},
                      {"           *         *    *                      *                      *   "},
                      {"           *         *       5-------------------6--------------------7     "},
                      {"           *         *       *                   *                  * *     "},
                      {"           *         *       *                   *              *     *     "},
                      {"           8---------9-------a          b--------c---------d          *     "},
                      {"           *         *       *          *                  *          *     "},
                      {"           *         *       *          *                  *          *     "},
                      {"           *         *       e----------f--------g         *          *     "},
                      {"           *         *                  *        *         *          *     "},
                      {"           *         *                  *        *         *          *     "},
                      {"           *         h-------i----------j        k---------l----------m     "},
                      {"           *     *            *                   *        *          *     "},
                      {"           * *               *                   *         *          *     "},
                      {"           o-----------------p-------------------q         *          *     "},
                      {"         *                   *                     *       *          *     "},
                      {"       *                     *                       *     *          *     "},
                      {"     *                       *                         *   *          *     "},
                      {"   *                         *                           * *          *     "},
                      {" r---------------------------s-----------------------------t          *     "},
                      {"                                                               *      *     "},
                      {"                                                                  *   *     "},
                      {"                                                                      u     "},
};



Field4::Field4()
{
    BOARD_SIZE = 29;
    boardRow = sizeof(BOARD) / sizeof(*BOARD);
    boardCol = sizeof(*BOARD) / sizeof(**BOARD);


    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board.push_back(0);
    }

}

void Field4::updateBoard()
{

    int X = 10;
    int x = 0;
    for (int i = 0; i < boardRow; i++)
    {
        for (int j = 0; j < boardCol; j++)
        {
            if ((BOARD[i][j] >= '1' && BOARD[i][j] <= '9') || (BOARD[i][j] >= 'a' && BOARD[i][j] <= 'z'))
            {

                if (board[x] != 0)
                {
                    cout << (board[x] == 1 ? "X" : "O");
                    x++;

                    if (BOARD[i][j] >= 'a' && BOARD[i][j] <= 'z')
                    {
                        X++;
                    }

                    continue;
                }
                x++;
            }


            if (BOARD[i][j] >= 'a' && BOARD[i][j] <= 'z')
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

bool Field4::checkForWining(int n)
{
    vector<int>& p = board;

    if (p[0] != 0 && p[0] == p[1] && p[1] == p[4])
    {
        return true;
    }

    if (p[1] != 0 && p[1] == p[2] && p[1] == p[3])
    {
        return true;
    }

    if (p[1] != 0 && p[1] == p[8] && p[1] == p[16])
    {
        return true;
    }

    if (p[2] != 0 && p[2] == p[5] && p[2] == p[11])
    {
        return true;
    }

    if (p[3] != 0 && p[3] == p[6] && p[3] == p[12])
    {
        return true;
    }

    if (p[0] != 0 && p[0] == p[7] && p[0] == p[22])
    {
        return true;
    }
    //3 az raste nachasb
    if (p[4] != 0 && p[4] == p[5] && p[4] == p[6])
    {
        return true;
    }

    if (p[4] != 0 && p[4] == p[9] && p[4] == p[13])
    {
        return true;
    }


    if (p[6] != 0 && p[6] == p[21] && p[6] == p[28])
    {
        return true;
    }

    //3 az chape nachasb
    if (p[7] != 0 && p[7] == p[8] && p[7] == p[9])
    {
        return true;
    }


    if (p[10] != 0 && p[10] == p[14] && p[10] == p[18])
    {
        return true;
    }


    if (p[10] != 0 && p[10] == p[11] && p[10] == p[12])
    {
        return true;
    }
    //-----------------------------kharabe------------------------------------------------
     /*if (p[12] != 0 && p[12] == p[20] && p[12] == p[27])
    {
        return true;
    }*/
    if (p[12] != 0 && p[12] == p[20] && p[12] == p[27])
    {
        return true;
    }
    /*if (p[12] != 0 && p[12] == p[20] && p[12] == p[27])
    {
        return true;
    }*/

    if (p[13] != 0 && p[13] == p[14] && p[13] == p[15])
    {
        return true;
    }


    if (p[15] != 0 && p[15] == p[19] && p[15] == p[24])
    {
        return true;
    }

    if (p[16] != 0 && p[16] == p[22] && p[16] == p[25])
    {
        return true;
    }

    if (p[16] != 0 && p[16] == p[17] && p[16] == p[18])
    {
        return true;
    }

    if (p[17] != 0 && p[17] == p[23] && p[17] == p[26])
    {
        return true;
    }

    if (p[19] != 0 && p[19] == p[20] && p[19] == p[21])
    {
        return true;
    }

    if (p[22] != 0 && p[22] == p[23] && p[22] == p[24])
    {
        return true;
    }

    if (p[24] != 0 && p[24] == p[27] && p[24] == p[28])
    {
        return true;
    }

    if (p[25] != 0 && p[25] == p[26] && p[25] == p[27])
    {
        return true;
    }

    if (p[15] != 0 && p[15] == p[19] && p[15] == p[24])
    {
        return true;
    }



    return false;
}


bool Field4::setPlace(int place, int p)
{
    if (board[place - 1] != 0)
        return false;

    board[place - 1] = p;
    return true;
}



bool Field4::checkForDraw()
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

int Field4::getInput(int p)
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



