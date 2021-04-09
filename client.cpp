#include <iostream>
#include <boost/asio.hpp>
#include <thread>

#define BOARD_SIZE 21
#define TIMER_SECS 20

#define CLEAR_SCREEN system("cls")

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

void updateBoard3();

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

static bool yourTurn;
static bool printWait = true;
static bool timerStarts;
static char yourCharacter;
static char opponentCharacter;
static io_service io;
static tcp::socket sock(io);
static int fieldNumber;
static bool loop;

int main()
{

    sock.connect(tcp::endpoint(address::from_string("127.0.0.1"), 1234));

    string text;



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


        if (text == "Which Field You Wanna Play?")
        {
            cout << text << " ";
            cout << "Number between 1 and 3" << endl;
            cout << ":-";

            int ans;
            do
            {
                cin >> ans;
                cin.get();

                if (ans >= 1 && ans <= 3)
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
    else if (text == "Lost")
    {
        cout << "---------You Lost----------" << endl;
        loop = false;
    }
    else if (isNumber(text))
    {
        int resp = stoi(text);
        setPlace(resp, (yourCharacter == 'X' ? 2 : 1));
        yourTurn = true;
        printWait = true;
    }
    else if (text == "exit")
    {
        loop = false;
    }

    this_thread::sleep_for(std::chrono::microseconds(500000));
}


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


void timer()
{
    while (loop)
    {
        if (timerStarts)
        {
            time_t t1 = time(NULL);
            while (timerStarts)
            {
                this_thread::sleep_for(std::chrono::microseconds(500000));
                if (difftime(time(NULL), t1) >= TIMER_SECS)
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

void getUserInput3()
{

    int ans;

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

void close()
{
    sendTo("exit\n");
    sock.close();
}
