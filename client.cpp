#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#ifdef _WIN32
#include <windows.h>

void sleep(unsigned milliseconds)
{
    Sleep(milliseconds);
}
#else
#include <unistd.h>

void sleep(unsigned milliseconds)
{
    usleep(milliseconds * 1000); // takes microseconds
}
#endif
#define BOARD_SIZE 21
#define TIMER_SECS 20

#define CLEAR_SCREEN system("cls")
#define BOARD_SIZE4 29


const char board4[][100] = {
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

static const int boardRow4 = sizeof(board4) / sizeof(*board4);
static const int boardCol4 = sizeof(*board4) / sizeof(**board4);

static int BOARD4[BOARD_SIZE4] = { 0 };
static int Winner4 = 0;
static bool firstP4 = true; //2 ta false*****************************


void updateBoard4();

bool checkForWinning4();
bool setPlace4(int place, int p);


using namespace std;

bool YourMove4 = true;

const char board[][100] = {
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

using namespace std;
using namespace boost::asio;
using namespace ip;

static const int boardRow = sizeof(board) / sizeof(*board);
static const int boardCol = sizeof(*board) / sizeof(**board);

static int BOARD[BOARD_SIZE] = { 0 };
static int Winner = 0;
vector<char> board2;
vector<char>  board1;

//int BOARD_SIZE1;
void updateBoard3();
void getUserInput4();
bool checkForWinning3();
bool setPlace(int place, int p);

void startGame();

void receiveFrom();
void sendTo(string text);
void timer();
bool isNumber(const string s);
void processCommand(string cmd);
void getUserInput3();
void close();
//void turn(vector<char>* board2);


void turn(vector<char>* board2);
void turn1(vector<char>* board1);

bool winConditionMet(vector<char>* board2);
bool winConditionMet1(vector<vector<char> >* board1, int BOARD_SIZE1);
//void turn1(vector<vector<char> >* board1, int BOARD_SIZE1);

static bool yourTurn;
static bool printWait = true;
static bool timerStarts;
static char yourCharacter;
static char opponentCharacter;
static io_service io;
static tcp::socket sock(io);
static int fieldNumber;
static bool loop;
static bool halghe;




void setplace2(int resp, vector<char>* board2) {
    (*board2)[resp] = opponentCharacter;

}
void setplace1(int resp, vector<char>* board1) {
    (*board1)[resp-1] = opponentCharacter;

}
bool setPlace4(int place, int p)
{
    if (BOARD4[place - 1] != 0)
        return false;

    BOARD4[place - 1] = p;
    return true;
}//Nem
vector<char>  buildBoard1() {

    vector<char> board1;



    for (int i = 0; i < 9; i++)
    {
        {
            board1.push_back(' ');
        }
    }

    return board1;
}


void printboard1(vector<char>* board1) {
    cout << endl << endl;
    cout << " 7(" << (*board1)[6] << ")----------8(" << (*board1)[7] << ")---------9(" << (*board1)[8] << ")" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << " 4(" << (*board1)[3] << ")----------5(" << (*board1)[4] << ")---------6(" << (*board1)[5] << ")" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << " 1(" << (*board1)[0] << ")----------2(" << (*board1)[1] << ")---------2(" << (*board1)[2] << ")" << endl;

}

vector<char>  buildBoard2() {

    vector<char> board2;
    for (int i = 0; i < 16; i++)
    {
        {
            board2.push_back(' ');
        }
    }

    return board2;
}


void printBoard2(vector<char>* board2) {
    cout << endl << endl;
    cout << "13(" << (*board2)[13] << ")---------14(" << (*board2)[14] << ")--------15(" << (*board2)[15] << ")" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |   10(" << (*board2)[10] << ")--11(" << (*board2)[11] << ")--12(" << (*board2)[12] << ")    |" << endl
        << "   |      |             |     |" << endl
        << " 6(" << (*board2)[6] << ")---7(" << (*board2)[7] << ")          8(" << (*board2)[8] << ")--9(" << (*board2)[9] << ")" << endl
        << "   |      |             |     |" << endl
        << "   |    3(" << (*board2)[3] << ")---4(" << (*board2)[4] << ")---5(" << (*board2)[5] << ")    |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << " 0(" << (*board2)[0] << ")----------1(" << (*board2)[1] << ")---------2(" << (*board2)[2] << ")" << endl;

}
int main()
{

    sock.connect(tcp::endpoint(address::from_string("127.0.0.1"), 1234));

    string text;
    board2 = buildBoard2();
    
    board1 = buildBoard1();


    //Wait until game statrs
    bool printed = false;
    while (1)
    {

        boost::asio::streambuf buff;

        read_until(sock, buff, "\n");
        text = buffer_cast<const char*>(buff.data());

        if (text == "Starting Game...\n")
        {
            cout << text;
            break;
        }

        atexit(close);
        if (!printed)
        {
            cout << text;
            printed = !printed;
        }

        this_thread::sleep_for(std::chrono::microseconds(500000));
    }

    //Get The Chosen Field 
    while (1)
    {
        text = "";
        boost::asio::streambuf buff;
        read_until(sock, buff, "\n");
        text = buffer_cast<const char*>(buff.data());
        text = text.substr(0, text.length() - 1);
        /*if (text == "          Main menu") {
            cout << text;
            continue;
        }*/

        if (text == "Which Field You Wanna Play?")
        {
            cout << text << " ";
            cout << "Number between 1 and 3" << endl;
            cout << ":-";

            printboard1(&board1);
            cout << endl << endl;
            cout << "               (1)" << endl;
            sleep(3000);
            system("cls");


            printBoard2((&board2));
            cout << endl << endl;
            cout << "               (2)" << endl;
            sleep(3000);
            system("cls");

            updateBoard3();
            cout << endl << endl;
            cout << "                          (3)" << endl;
            sleep(3000);
            system("cls");
            updateBoard4();
            cout << endl << endl;
            cout << "                          (4)" << endl;
            sleep(3000);
            system("cls");
            int ans;
            do
            {
                cin >> ans;
                cin.get();

                if (ans >= 1 && ans <= 4)
                    break;

                cin.clear();
                cout << "Wrong answer! try again: ";

            } while (1);

            fieldNumber = ans;
            //Do Stuff aftert Filed Has been chosen like set the BOARD and ...



            //Sending Answer to server
            string str = to_string(fieldNumber) + "\n";
            sendTo(str);
            continue;
        }

        if (isNumber(text))
        {
            fieldNumber = stoi(text);
            //Do Stuff aftert Filed Has been chosen like set the BOARD and ...


            continue;
        }


        if (text == "true" || text == "false")
        {
            if (text == "true")
            {
                yourTurn = true;
                yourCharacter = 'X';
                opponentCharacter = 'O';
            }
            else if (text == "false")
            {
                yourTurn = false;
                opponentCharacter = 'X';
                yourCharacter = 'O';
            }
            else
            {
                cerr << "Wrong Server Respond!" << endl;
                return 1;
            }

            break;
        }


        this_thread::sleep_for(std::chrono::microseconds(500000));
    }

    loop = true;
    halghe = true;
    thread t1(timer);
    thread t2(receiveFrom);
    thread t3(startGame);

    t1.join();
    t2.join();
    t3.join();

}


void sendTo(string text)
{
    write(sock, boost::asio::buffer(text));
}


void receiveFrom()
{


    string text;
    while (loop)
    {
        try
        {
            text = "";
            boost::asio::streambuf buff;
            read_until(sock, buff, "\n");
            text = buffer_cast<const char*>(buff.data());

            processCommand(text);
        }
        catch (...)
        {
            loop = false;
            break;
        }
    }

}

bool isNumber(const string s)
{
    if (s.empty())
        return false;

    for (char c : s)
    {
        if (c == '\n')
            continue;

        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}

void processCommand(string text)
{
    if (text.empty())
        return;

    if (text.find('\n') != string::npos)
        text = text.substr(0, text.length() - 1);

    if (text == "left")
    {
        cout << "---------You Won----------" << endl;
        loop = false;
        exit(0);
    }
    //else if (text[0] == '(') {
    //    int xInput = 0;
    //    int yInput = 0;
    //    xInput = (int)text[1] - 48;//char ro be adad convert konim:)
    //    yInput = (int)text[3] - 48;

    //    setplace1(xInput, yInput, &board1);
    //    yourTurn = true;

    //    printWait = true;
    //}
    else if (text == "Lost")
    {
        cout << "---------You Lost----------" << endl;
        loop = false;
    }
    else if (text == "NO")
    {
        cout << "---------NO WINNER----------" << endl;
        loop = false;
        //exit(0);
    }


    else if (isNumber(text))
    {
        int resp = stoi(text);

        if (fieldNumber == 3)
            setPlace(resp, (yourCharacter == 'X' ? 2 : 1));
        else if (fieldNumber == 2)
            //(*board2)[resp] = yourCharacter;
            setplace2(resp, &board2);
        else if (fieldNumber == 1)
            //(*board2)[resp] = yourCharacter;
            setplace1(resp, &board1);
        else if (fieldNumber == 4)
            setPlace4(resp, (yourCharacter == 'X' ? 2 : 1));
        yourTurn = true;
        printWait = true;
    }
    else if (text == "exit")
    {
        loop = false;
    }

    this_thread::sleep_for(std::chrono::microseconds(500000));
}

void updateBoard4()
{

    system("cls");

    //Part 2
    int X = 10;
    int x = 0;
    for (int i = 0; i < boardRow4; i++)
    {
        for (int j = 0; j < boardCol4; j++)
        {
            if ((board4[i][j] >= '1' && board4[i][j] <= '9') || (board4[i][j] >= 'a' && board4[i][j] <= 'z'))
            {

                if (BOARD4[x] != 0)
                {
                    cout << (BOARD4[x] == 1 ? "X" : "O");
                    x++;

                    if (board4[i][j] >= 'a' && board4[i][j] <= 'z')
                    {
                        X++;
                    }

                    continue;
                }
                x++;
            }


            if (board4[i][j] >= 'a' && board4[i][j] <= 'z')
            {
                //check the array
                cout << X++;
                j++;
            }
            else
            {
                cout << board4[i][j];
            }
        }

        cout << endl;
    }

    cout << endl;

}//end of function


void updateBoard3()
{

    CLEAR_SCREEN;

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



bool checkForWinning4()
{

    int* p = BOARD4;

    if (p[0] != 0 && p[0] == p[1] && p[1] == p[4])
    {
        Winner4 = p[0];
        return true;
    }

    if (p[1] != 0 && p[1] == p[2] && p[1] == p[3])
    {
        Winner4 = p[3];
        return true;
    }

    if (p[1] != 0 && p[1] == p[8] && p[1] == p[16])
    {
        Winner4 = p[1];
        return true;
    }

    if (p[2] != 0 && p[2] == p[5] && p[2] == p[11])
    {
        Winner4 = p[2];
        return true;
    }

    if (p[3] != 0 && p[3] == p[6] && p[3] == p[12])
    {
        Winner4 = p[3];
        return true;
    }

    if (p[0] != 0 && p[0] == p[7] && p[0] == p[22])
    {
        Winner4 = p[0];
        return true;
    }
    //3 az raste nachasb
    if (p[4] != 0 && p[4] == p[5] && p[4] == p[6])
    {
        Winner4 = p[4];
        return true;
    }

    if (p[4] != 0 && p[4] == p[9] && p[4] == p[13])
    {
        Winner4 = p[4];
        return true;
    }


    if (p[6] != 0 && p[6] == p[21] && p[6] == p[28])
    {
        Winner4 = p[6];
        return true;
    }

    //3 az chape nachasb
    if (p[7] != 0 && p[7] == p[8] && p[7] == p[9])
    {
        Winner4 = p[7];
        return true;
    }


    if (p[10] != 0 && p[10] == p[14] && p[10] == p[18])
    {
        Winner4 = p[10];
        return true;
    }


    if (p[10] != 0 && p[10] == p[11] && p[10] == p[12])
    {
        Winner4 = p[10];
        return true;
    }
    //-----------------------------kharabe------------------------------------------------
     /*if (p[12] != 0 && p[12] == p[20] && p[12] == p[27])
    {
        Winner4 = p[10];
        return true;
    }*/
    if (p[12] != 0 && p[12] == p[20] && p[12] == p[27])
    {
        Winner4 = p[12];
        return true;
    }
    /*if (p[12] != 0 && p[12] == p[20] && p[12] == p[27])
    {
        Winner4 = p[11];
        return true;
    }*/

    if (p[13] != 0 && p[13] == p[14] && p[13] == p[15])
    {
        Winner4 = p[13];
        return true;
    }


    if (p[15] != 0 && p[15] == p[19] && p[15] == p[24])
    {
        Winner4 = p[15];
        return true;
    }

    if (p[16] != 0 && p[16] == p[22] && p[16] == p[25])
    {
        Winner4 = p[16];
        return true;
    }

    if (p[16] != 0 && p[16] == p[17] && p[16] == p[18])
    {
        Winner4 = p[16];
        return true;
    }

    if (p[17] != 0 && p[17] == p[23] && p[17] == p[26])
    {
        Winner4 = p[17];
        return true;
    }

    if (p[19] != 0 && p[19] == p[20] && p[19] == p[21])
    {
        Winner4 = p[19];
        return true;
    }

    if (p[22] != 0 && p[22] == p[23] && p[22] == p[24])
    {
        Winner4 = p[22];
        return true;
    }

    if (p[24] != 0 && p[24] == p[27] && p[24] == p[28])
    {
        Winner4 = p[24];
        return true;
    }

    if (p[25] != 0 && p[25] == p[26] && p[25] == p[27])
    {
        Winner4 = p[25];
        return true;
    }

    if (p[15] != 0 && p[15] == p[19] && p[15] == p[24])
    {
        Winner4 = p[15];
        return true;
    }



    return false;
}//End of check for Winner4 function

bool checkForWinning3()
{

    int* p = BOARD;

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
}//End of check for Winner function


bool setPlace(int place, int p)
{
    if (BOARD[place - 1] != 0)
        return false;

    BOARD[place - 1] = p;
    return true;
}

void startGame()
{


    if (fieldNumber == 1) {
        // int BOARD_SIZE1 = 3, bead, level;
         //vector<vector<char> > board1;
         //vector<vector<int> > board1int;
        // int shouldGameContinue = 0;
         //int playerSwitch = 1;

        cout << "Hello! Welcome to Tic Tac Toe!" << endl;
        cout << "name of board:tic tac toe " << endl;
        cout << "size of board:3"  << endl;
       
            cout << "number of plots:3" << endl;
       
        sleep(7000);
        while (loop)
        {

            if (printWait)
            {
                //updateBoard3();

                system("cls");
                // printBoard2((&board2));
                // printBoard1int(&board1int, BOARD_SIZE1);
                printboard1(&board1);
                cout << endl;
                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {


                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << TIMER_SECS << " seconds to move" << endl;
                timerStarts = true;

                //getUserInput3();
                turn1(&board1);
                //system("cls");

                printWait = true;

            }
            else
            {
                if (printWait)
                {
                    cout << "Waiting for Opponent Move..." << endl;
                    printWait = false;
                }

                this_thread::sleep_for(std::chrono::microseconds(500000));
            }
        }

    }
    else if (fieldNumber == 2) {
        int ans;
        //int bead;
        //int shouldGameContinue = 0;
        //int playerSwitch = 1;
        cout << "Hello! Welcome to six men's morris!" << endl;
        cout << "name of board:six men's morris" << endl;
        cout << "size of board:3" << endl;
        cout << "number of plots:3" << endl;
        sleep(2000);
        while (loop)
        {

            if (printWait)
            {
                //updateBoard3();

                system("cls");
                printBoard2((&board2));
                cout << endl;
                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {
                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << TIMER_SECS << " seconds to move" << endl;
                timerStarts = true;

                //getUserInput3();
                turn((&board2));
                printWait = true;

            }
            else
            {
                if (printWait)
                {
                    cout << "Waiting for Opponent Move..." << endl;
                    printWait = false;
                }

                this_thread::sleep_for(std::chrono::microseconds(500000));
            }
        }

    }
    else if (fieldNumber == 3) {
        int ans;

        while (loop)
        {

            if (printWait)
            {
                updateBoard3();
                cout << endl;
                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {
                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << TIMER_SECS << " seconds to move" << endl;
                timerStarts = true;

                getUserInput3();
                // turn((&board2));
                printWait = true;

            }
            else
            {
                if (printWait)
                {
                    cout << "Waiting for Opponent Move..." << endl;
                    printWait = false;
                }

                this_thread::sleep_for(std::chrono::microseconds(500000));
            }
        }
    }
    else if (fieldNumber == 4) {
        int ans;

        while (loop)
        {

            if (printWait)
            {
                updateBoard4();
                cout << endl;
                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {
                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << TIMER_SECS << " seconds to move" << endl;
                timerStarts = true;

                getUserInput4();
                // turn((&board2));
                printWait = true;

            }
            else
            {
                if (printWait)
                {
                    cout << "Waiting for Opponent Move..." << endl;
                    printWait = false;
                }

                this_thread::sleep_for(std::chrono::microseconds(500000));
            }
        }

    }

}


void timer()
{

    int counter = 9;
    while (loop)
    {
        if (timerStarts)
        {
            time_t t1 = time(NULL);
            // time_t t2 = t1;
            halghe = true;
            while (timerStarts)
            {

                Sleep(1500);
                while (counter >= 1 && halghe)
                {

                    cout << "\rTime remaining: " << counter << " " << flush;
                    Sleep(1500);

                    counter--;
                }
                counter = 9;
                // this_thread::sleep_for(std::chrono::microseconds(500000));


                if (difftime(time(NULL), t1) >= 9)
                {
                    sendTo("left\n");
                    cout << "\nTime Out! You Lost!" << endl;
                    loop = false;
                    exit(0);
                }

            }
        }

        this_thread::sleep_for(std::chrono::microseconds(500000));
    }
}
void getUserInput4()
{

    int ans;

    cout << "Choose the place you wanna go: ";
    do
    {
        if (cin >> ans)
        {
            halghe = false;
            if (ans >= 0 && ans <= 29)
            {
                if (ans == 0)
                {
                    loop = false;
                    sendTo("left\n");
                    break;
                }

                if (setPlace4(ans, (yourCharacter == 'X' ? 1 : 2)))
                    break;
            }
        }

        cin.clear();
        cout << "Wrong Answer! try again: ";
    } while (true);
    /// <summary>
    /// ///
    /// </summary>
    if (checkForWinning4())
    {
        loop = false;
        cout << "---------You Won----------" << endl;
        sendTo("winner\n");
        loop = false;
    }
    else
    {
        sendTo(to_string(ans) + "\n");
    }

    this_thread::sleep_for(std::chrono::microseconds(1000000));
    sendTo(to_string(ans) + "\n");
    yourTurn = false;
    timerStarts = false;

}

void getUserInput3()
{

    int ans;

    cout << "Choose the place you wanna go: " << endl;
    do
    {
        if (cin >> ans)
        {
            halghe = false;
            if (ans >= 0 && ans <= 21)
            {
                if (ans == 0)
                {
                    loop = false;
                    sendTo("left\n");
                    break;
                }

                if (setPlace(ans, (yourCharacter == 'X' ? 1 : 2)))
                    break;
            }
        }

        cin.clear();
        cout << "Wrong Answer! try again: ";
    } while (true);

    if (checkForWinning3())
    {
        loop = false;
        cout << "---------You Won----------" << endl;
        sendTo("winner\n");
        loop = false;
    }
    else
    {
        sendTo(to_string(ans) + "\n");
    }

    this_thread::sleep_for(std::chrono::microseconds(1000000));
    sendTo(to_string(ans) + "\n");
    yourTurn = false;
    timerStarts = false;

}
bool winConditionMet(vector<char>* board2) {



    if ((*board2)[0] == yourCharacter && (*board2)[1] == yourCharacter && (*board2)[2] == yourCharacter || (*board2)[3] == yourCharacter && (*board2)[4] == yourCharacter && (*board2)[5] == yourCharacter || (*board2)[10] == yourCharacter && (*board2)[11] == yourCharacter && (*board2)[12] == yourCharacter || (*board2)[13] == yourCharacter && (*board2)[14] == yourCharacter && (*board2)[15] == yourCharacter || (*board2)[0] == yourCharacter && (*board2)[6] == yourCharacter && (*board2)[13] == yourCharacter || (*board2)[3] == yourCharacter && (*board2)[7] == yourCharacter && (*board2)[10] == yourCharacter || (*board2)[5] == yourCharacter && (*board2)[8] == yourCharacter && (*board2)[12] == yourCharacter || (*board2)[2] == yourCharacter && (*board2)[9] == yourCharacter && (*board2)[15] == yourCharacter) {



        return true;
    }

    int countAllGone = 0;
    for (int i = 0; i < 16; i++) {

        if ((*board2)[i] != ' ')

        {
            countAllGone++;
        }
    }
    if (countAllGone == 16) {
        loop = false;
        cout << "---------NO WINNER!----------" << endl;
        sendTo("N\n");
        loop = false;

    }



    else
        return false;
    //return 0;
}
bool winConditionMet1(vector<char >* board1) {

    // Check Horizontally

    if ((*board1)[0] == yourCharacter && (*board1)[1] == yourCharacter && (*board1)[2] == yourCharacter || (*board1)[3] == yourCharacter && (*board1)[4] == yourCharacter && (*board1)[5] == yourCharacter || (*board1)[6] == yourCharacter && (*board1)[7] == yourCharacter && (*board1)[8] == yourCharacter || (*board1)[0] == yourCharacter && (*board1)[3] == yourCharacter && (*board1)[6] == yourCharacter || (*board1)[1] == yourCharacter && (*board1)[4] == yourCharacter && (*board1)[7] == yourCharacter || (*board1)[2] == yourCharacter && (*board1)[5] == yourCharacter && (*board1)[8] == yourCharacter || (*board1)[0] == yourCharacter && (*board1)[8] == yourCharacter && (*board1)[4] == yourCharacter || (*board1)[2] == yourCharacter && (*board1)[4] == yourCharacter && (*board1)[7] == yourCharacter) {



        return true;
    }


    // Check if there is no winner

    int countAllGone = 0;
    for (int i = 0; i < 9; i++) {

        if ((*board1)[i] != ' ')

        {
            countAllGone++;
        }
    }
    if (countAllGone == 9) {
        loop = false;
        cout << "NO WINNER!" << endl;
        //exit(0);
        sendTo("N\n");
        loop = false;
    }
    else
        return false;
}
void turn(vector<char>* board2) {

    int Input;
    bool validInput = false;


    // cout << "PLAYER 1 TURN!" << endl;////

    while (!validInput) {
        cout << "Type the number of your position:)" << endl;
        cin >> Input;
        halghe = false;
        if ((*board2)[Input] == 'O' ||
            (*board2)[Input] == 'X' ||
            Input > 15 ||
            Input < 0) {
            cout << "Not Valid Input. Spot is already taken!" << endl;
        }
        else {
            validInput = true;
        }
    }
    (*board2)[Input] = yourCharacter;
    //  else
     //     (*board2)[xInput - 1][yInput - 1] = 'o';
    // Check if there is no winner


    if (winConditionMet(board2))
    {
        loop = false;
        cout << "---------You Won----------" << endl;
        sendTo("winner\n");
        loop = false;
    }
    else
    {
        sendTo(to_string(Input) + "\n");
    }

    this_thread::sleep_for(std::chrono::microseconds(1000000));
    sendTo((to_string(Input) + "\n"));
    yourTurn = false;
    timerStarts = false;//shayad bayad ino jasho avaz konam.ah.fuck


}
void turn1(vector<char >* board1) {

    int input;
    bool validInput = false;
   // int xInput = 0;
   // int yInput = 0;

    while (!validInput) {
        cout << "Type the number of your position:)" << endl;
        //timerStarts = true;
        cin >> input;
        halghe = false;
      //  xInput = (int)input[1] - 48;//char ro be adad convert konim:)
       // yInput = (int)input[3] - 48;

        if ((*board1)[input-1] == 'O' ||
            (*board1)[input - 1]=='X' ||
            input  > 9 ||
            input  < 1) {
            cout << "Not Valid Input. Spot is already taken!" << endl;
        }
        else {
            validInput = true;
        }
    }

    (*board1)[input - 1] = yourCharacter;

 if (winConditionMet1(board1))///
    {
        loop = false;
        cout << "---------You Won----------" << endl;
        sendTo("winner\n");
        loop = false;
    }
    else
    {
        sendTo(to_string(input)+"\n");
    }



    this_thread::sleep_for(std::chrono::microseconds(1000000));
    sendTo(to_string(input)+"\n");
    yourTurn = false;
    timerStarts = false;


}

void close()
{
    sendTo("exit\n");
    sock.close();
}
