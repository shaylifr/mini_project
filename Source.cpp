#include <iostream>
#include <iomanip>

#include <time.h>

#define BOARD_SIZE 29


const char board[][100] = {
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

static const int boardRow = sizeof(board) / sizeof(*board);
static const int boardCol = sizeof(*board) / sizeof(**board);

static int BOARD[BOARD_SIZE] = { 0 };
static int Winner = 0;
static bool firstP = true; 


void updateBoard();

bool checkForWinning();
bool setPlace(int place, int p);


using namespace std;

bool YourMove = true;
int main()
{

    bool loop = true;

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
                if (ans >= 0 && ans <= 29)
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
            if ((board[i][j] >= '1' && board[i][j] <= '9') || (board[i][j] >= 'a' && board[i][j] <= 'z'))
            {

                if (BOARD[x] != 0)
                {
                    cout << (BOARD[x] == 1 ? "X" : "O");
                    x++;

                    if (board[i][j] >= 'a' && board[i][j] <= 'z')
                    {
                        X++;
                    }

                    continue;
                }
                x++;
            }


            if (board[i][j] >= 'a' && board[i][j] <= 'z')
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

    if (p[0] != 0 && p[0] == p[1] && p[1] == p[4])
    {
        Winner = p[0];
        return true;
    }

    if (p[1] != 0 && p[1] == p[2] && p[1] == p[3])
    {
        Winner = p[3];
        return true;
    }

    if (p[1] != 0 && p[1] == p[8] && p[1] == p[16])
    {
        Winner = p[1];
        return true;
    }

    if (p[2] != 0 && p[2] == p[5] && p[2] == p[11])
    {
        Winner = p[2];
        return true;
    }

    if (p[3] != 0 && p[3] == p[6] && p[3] == p[12])
    {
        Winner = p[3];
        return true;
    }

    if (p[0] != 0 && p[0] == p[7] && p[0] == p[22])
    {
        Winner = p[0];
        return true;
    }
    
    if (p[4] != 0 && p[4] == p[5] && p[4] == p[6])
    {
        Winner = p[4];
        return true;
    }

    if (p[4] != 0 && p[4] == p[9] && p[4] == p[13])
    {
        Winner = p[4];
        return true;
    }


    if (p[6] != 0 && p[6] == p[21] && p[6] == p[28])
    {
        Winner = p[6];
        return true;
    }

    if (p[7] != 0 && p[7] == p[8] && p[7] == p[9])
    {
        Winner = p[7];
        return true;
    }


    if (p[10] != 0 && p[10] == p[14] && p[10] == p[18])
    {
        Winner = p[10];
        return true;
    }


    if (p[10] != 0 && p[10] == p[11] && p[10] == p[12])
    {
        Winner = p[10];
        return true;
    }
    
    if (p[12] != 0 && p[12] == p[20] && p[12] == p[27])
    {
        Winner = p[12];
        return true;
    }
    
    if (p[13] != 0 && p[13] == p[14] && p[13] == p[15])
    {
        Winner = p[13];
        return true;
    }


    if (p[15] != 0 && p[15] == p[19] && p[15] == p[24])
    {
        Winner = p[15];
        return true;
    }

    if (p[16] != 0 && p[16] == p[22] && p[16] == p[25])
    {
        Winner = p[16];
        return true;
    }

    if (p[16] != 0 && p[16] == p[17] && p[16] == p[18])
    {
        Winner = p[16];
        return true;
    }

    if (p[17] != 0 && p[17] == p[23] && p[17] == p[26])
    {
        Winner = p[17];
        return true;
    }

    if (p[19] != 0 && p[19] == p[20] && p[19] == p[21])
    {
        Winner = p[19];
        return true;
    }

    if (p[22] != 0 && p[22] == p[23] && p[22] == p[24])
    {
        Winner = p[22];
        return true;
    }

    if (p[24] != 0 && p[24] == p[27] && p[24] == p[28])
    {
        Winner = p[24];
        return true;
    }

    if (p[25] != 0 && p[25] == p[26] && p[25] == p[27])
    {
        Winner = p[25];
        return true;
    }

    if (p[15] != 0 && p[15] == p[19] && p[15] == p[24])
    {
        Winner = p[15];
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

