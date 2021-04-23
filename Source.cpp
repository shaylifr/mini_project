#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include "field1.h"
#include "field2.h"
#include "field3.h"
#include "field4.h"
#include <conio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define CLEAR_SCREEN system("cls")
#define TIMER_SECS 20000

using namespace std;
using namespace boost::asio;
using namespace ip;

void startGame();

void receiveFrom();
void sendTo(string text);
void timer();
bool isNumber(const string s);
void processCommand(string cmd);
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
static bool halghe;
static int player;
static Field1 field1;
static Field2 field2;
static Field3 field3;
static Field4 field4;

void winner()
{
    loop = false;
    timerStarts = false;
    if (fieldNumber == 1) {
        CLEAR_SCREEN;
        field1.updateBoard();
    }
    else if (fieldNumber == 2) {
        CLEAR_SCREEN;
        field2.updateBoard();
    }
    else if (fieldNumber == 3) {
        CLEAR_SCREEN;
        field3.updateBoard();
    }
    else if (fieldNumber == 4) {
        CLEAR_SCREEN;
        field4.updateBoard();
    }
    cout << ANSI_COLOR_GREEN"---------You Won----------" ANSI_COLOR_RESET << endl;
    sendTo("winner\n");
    loop = false;
    exit(0);
    this_thread::sleep_for(std::chrono::microseconds(1000000));
}

void left()
{
    loop = false;
    timerStarts = false;
    cout << ANSI_COLOR_RED "---------You Left----------"  ANSI_COLOR_RESET << endl;
    sendTo("left\n");
    this_thread::sleep_for(std::chrono::microseconds(1000000));

}
void timeout()
{
    loop = false;
    timerStarts = false;
    cout << ANSI_COLOR_RED "---------Time out----------"  ANSI_COLOR_RESET << endl;
    sendTo("left\n");
    this_thread::sleep_for(std::chrono::microseconds(1000000));

}

void draw()
{
    loop = false;
    timerStarts = false;

    cout << ANSI_COLOR_YELLOW "NO WINNER!" ANSI_COLOR_RESET << endl;
    sendTo("draw\n");
    this_thread::sleep_for(std::chrono::microseconds(1000000));

}


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
            cout << "Number between 1 and 4" << endl;
            cout << ":-";

            field1.updateBoard();
            cout << endl << endl;
            cout << "               (1)" << endl;
            this_thread::sleep_for(std::chrono::milliseconds(3000));
            // CLEAR_SCREEN;


            field2.updateBoard();
            cout << endl << endl;
            cout << "               (2)" << endl;
            this_thread::sleep_for(std::chrono::milliseconds(3000));
            //CLEAR_SCREEN;

            field3.updateBoard();
            cout << endl << endl;
            cout << "                          (3)" << endl;
            this_thread::sleep_for(std::chrono::milliseconds(3000));
            //CLEAR_SCREEN;

            field4.updateBoard();
            cout << endl << endl;
            cout << "                          (4)" << endl;
            this_thread::sleep_for(std::chrono::milliseconds(3000));
            // CLEAR_SCREEN;

            int ans;
            do
            {
                cin >> ans;
                cin.get();

                if (ans >= 1 && ans <= 4)
                    break;

                cin.clear();
                cout << ANSI_COLOR_RED "Wrong answer! try again: "  ANSI_COLOR_RESET;

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
                player = 1;
                yourCharacter = 'X';
                opponentCharacter = 'O';
            }
            else if (text == "false")
            {
                yourTurn = false;
                player = 2;
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
        cout << ANSI_COLOR_GREEN"---------You Won----------" ANSI_COLOR_RESET << endl;
        loop = false;
        exit(0);
    }

    else if (text == "Lost")
    {
        if (fieldNumber == 1) {
            system("cls");
            field1.updateBoard();
        }

        else if (fieldNumber == 2) {
            system("cls");
            field2.updateBoard();
        }
        else if (fieldNumber == 3) {
            system("cls");
            field3.updateBoard();
        }
        else if (fieldNumber == 4) {
            system("cls");
            field4.updateBoard();
        }
        timerStarts = false;
        cout << ANSI_COLOR_RED "---------You Lost----------"  ANSI_COLOR_RESET << endl;
        loop = false;
        exit(0);
    }
    else if (text == "NO")
    {

        timerStarts = false;
        loop = false;
        cout << ANSI_COLOR_MAGENTA "---------NO WINNER----------" ANSI_COLOR_RESET << endl;

    }


    else if (isNumber(text))
    {
        int resp = stoi(text);

        if (fieldNumber == 3)
            field3.setPlace(resp, (player == 1 ? 2 : 1));
        else if (fieldNumber == 2)
            //(*board2)[resp] = yourCharacter;
            field2.setPlace(resp, (player == 1 ? 2 : 1));
        else if (fieldNumber == 1)
            field1.setPlace(resp, (player == 1 ? 2 : 1));
        else if (fieldNumber == 4)
            field4.setPlace(resp, (player == 1 ? 2 : 1));
        yourTurn = true;
        printWait = true;
    }
    else if (text == "exit")
    {
        loop = false;
    }

    this_thread::sleep_for(std::chrono::microseconds(500000));
}


void startGame()
{

    halghe = false;

    if (fieldNumber == 1) {

        CLEAR_SCREEN;
        cout << ANSI_COLOR_CYAN "Hello!Welcome to the game!" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "name of board:tic tac toe " ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "size of board:3" ANSI_COLOR_RESET << endl;

        cout << ANSI_COLOR_CYAN "number of plots:3" ANSI_COLOR_RESET << endl;
        this_thread::sleep_for(std::chrono::milliseconds(2000));
        //system("Cls");
        char h = 16;
        char k = 220;
        char p = 219;
        char name[9] = { 'L','O','A','D','i','N','G' };

        system("cls");
        int i;
        for (i = 0; i < 8; i++) {

            system("color 4");
            system("color 2");
            system("color 1");
            system("color 5");
            system("color 3");

            if (i < 6)
                cout << name[i] << " ";
            else
                cout << name[i];
        }

        this_thread::sleep_for(std::chrono::milliseconds(7000));
        while (loop)
        {


            if (printWait)
            {


                CLEAR_SCREEN;

                field1.updateBoard();// ************

                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {


                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << 20 << " seconds to move" << endl;
                timerStarts = true;
                halghe = true;


                int ret = field1.getInput(player);
                yourTurn = false;
                timerStarts = false;
                halghe = false;

                if (ret == 0)
                {
                    left();
                    continue;
                }
                sendTo(to_string(ret) + "\n");

                if (field1.checkForWining(player))
                {
                    winner();
                    continue;
                }

                if (field1.checkForDraw())
                {
                    draw();
                    continue;
                }


                this_thread::sleep_for(std::chrono::microseconds(1000000));

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
        CLEAR_SCREEN;
        cout << ANSI_COLOR_CYAN "Hello!Welcome to the game!" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "name of board:six men's morris" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "size of board:3" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "number of plots:3" ANSI_COLOR_RESET << endl;
        this_thread::sleep_for(std::chrono::milliseconds(2000));
        char h = 16;
        char k = 220;
        char p = 219;
        char name[9] = { 'L','O','A','D','i','N','G' };

        system("cls");
        int i;
        for (i = 0; i < 8; i++) {

            system("color 4");
            system("color 2");
            system("color 1");
            system("color 5");
            system("color 3");

            if (i < 6)
                cout << name[i] << " ";
            else
                cout << name[i];
        }

        this_thread::sleep_for(std::chrono::milliseconds(2000));
        while (loop)
        {

            if (printWait)
            {

                CLEAR_SCREEN;
                field2.updateBoard();
                cout << endl;
                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {
                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << 20 << " seconds to move" << endl;
                timerStarts = true;
                halghe = true;


                int ret = field2.getInput(player);

                printWait = true;
                yourTurn = false;
                timerStarts = false;
                halghe = false;

                if (ret == 0)
                {
                    left();
                    continue;
                }
                sendTo(to_string(ret) + "\n");
                if (field2.checkForWining(player))
                {
                    winner();
                    continue;
                }

                if (field2.checkForDraw())
                {
                    draw();
                    continue;
                }


                this_thread::sleep_for(std::chrono::microseconds(1000000));

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
        CLEAR_SCREEN;
        cout << ANSI_COLOR_CYAN "Hello!Welcome to the game!" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "name of board:mill" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "size of board:3" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "number of plots:3" ANSI_COLOR_RESET << endl;
        this_thread::sleep_for(std::chrono::milliseconds(2000));
        char h = 16;
        char k = 220;
        char p = 219;
        char name[9] = { 'L','O','A','D','i','N','G' };

        CLEAR_SCREEN;
        int i;
        for (i = 0; i < 8; i++) {

            system("color 4");
            system("color 2");
            system("color 1");
            system("color 5");
            system("color 3");

            if (i < 6)
                cout << name[i] << " ";
            else
                cout << name[i];
        }

        while (loop)
        {

            if (printWait)
            {
                CLEAR_SCREEN;
                field3.updateBoard();
                cout << endl;
                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {
                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << 20 << " seconds to move" << endl;
                timerStarts = true;

                int ret = field3.getInput(player);
                printWait = true;
                yourTurn = false;
                timerStarts = false;

                if (ret == 0)
                {
                    left();
                    continue;
                }
                sendTo(to_string(ret) + "\n");
                if (field3.checkForWining(player))
                {
                    winner();
                    continue;
                }

                if (field3.checkForDraw())
                {
                    draw();
                    continue;
                }


                this_thread::sleep_for(std::chrono::microseconds(1000000));
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
        CLEAR_SCREEN;
        cout << ANSI_COLOR_CYAN "Hello!Welcome to the game!" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "name of board:star tic tac toe" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "size of board:3" ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_CYAN "number of plots:3" ANSI_COLOR_RESET << endl;
        this_thread::sleep_for(std::chrono::milliseconds(2000));
        char h = 16;
        char k = 220;
        char p = 219;
        char name[9] = { 'L','O','A','D','i','N','G' };

        CLEAR_SCREEN;
        int i;
        for (i = 0; i < 8; i++) {

            system("color 4");
            system("color 2");
            system("color 1");
            system("color 5");
            system("color 3");

            if (i < 6)
                cout << name[i] << " ";
            else
                cout << name[i];
        }

        while (loop)
        {

            if (printWait)
            {
                CLEAR_SCREEN;
                field4.updateBoard();
                cout << endl;
                cout << "You = " << yourCharacter << "\t";
                cout << "Opponent = " << opponentCharacter << endl;

                cout << "--- Current Turn: " << (yourTurn ? "You" : "Opponent") << " ---" << endl;
            }

            if (yourTurn)
            {
                cout << "Enter \'0\' to exit" << endl;
                cout << "You Have " << 20 << " seconds to move" << endl;
                timerStarts = true;

                int ret = field4.getInput(player);
                printWait = true;
                yourTurn = false;
                timerStarts = false;

                if (ret == 0)
                {
                    left();
                    continue;
                }
                sendTo(to_string(ret) + "\n");
                if (field4.checkForWining(player))
                {
                    winner();
                    continue;
                }

                if (field4.checkForDraw())
                {
                    draw();
                    continue;
                }


                this_thread::sleep_for(std::chrono::microseconds(1000000));
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

    int seconds = TIMER_SECS / 1000;
    int counter = 20;
    while (loop)
    {
        if (timerStarts)
        {
            time_t t1 = time(NULL);

            halghe = true;
            while (timerStarts)
            {

                while (loop && counter >= 1 && halghe && timerStarts)
                {

                    cout << ANSI_COLOR_RED "\rTime remaining: "  ANSI_COLOR_RESET << counter << " " << flush;

                    this_thread::sleep_for(std::chrono::milliseconds(1000));
                    counter--;
                }
                counter = 20;


                if (difftime(time(NULL), t1) >= seconds)
                {
                    timeout();
                }

            }
        }

        this_thread::sleep_for(std::chrono::microseconds(500000));
    }
}
