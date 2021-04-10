#include <iostream>
#include <boost/asio.hpp>
#include <ctype.h>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost::asio;
using namespace ip;


static bool loop;

bool isNumber(const string s)
{
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

void sendTo(tcp::socket& sock, string msg)
{
    write(sock, boost::asio::buffer(msg));
}

void processAndRespond(tcp::socket& sock, string& text)
{
    if (text.empty())
        return;

    if (text.find('\n') != string::npos)
        text = text.substr(0, text.length() - 1);

    if (isNumber(text))
    {
        // cout << "h";
        sendTo(sock, text + "\n");
    }
    else if (text[1] == '^') {

        sendTo(sock, text + "\n");

    }
    else if (text[0] == '(') {

        sendTo(sock, text + "\n");

    }
    else if (text[2] == '*') {
        //cout << "hm";
        sendTo(sock, text + "\n");

    }

    else if (text == "left")
    {
        sendTo(sock, "left\n");
        this_thread::sleep_for(std::chrono::microseconds(500000));

    }
    else if (text == "winner")
    {
        sendTo(sock, "Lost\n");
        this_thread::sleep_for(std::chrono::microseconds(500000));
    }
    else if (text == "loser")
    {
        sendTo(sock, "Won\n");
        this_thread::sleep_for(std::chrono::microseconds(500000));

    }
    else if (text == "exit")
    {
        loop = false;
        exit(0);
    }


}


void receiveFrom(tcp::socket& sock, tcp::socket& sock2)
{

    string text;
    size_t s;
    while (loop)
    {
        try
        {

            boost::asio::streambuf buff;
            text = "";
            //Client 1
            read_until(sock, buff, "\n");
            text = buffer_cast<const char*>(buff.data());

            processAndRespond(sock2, text);
        }
        catch (...)
        {
            loop = false;
            break;
        }
    }

}

int main()

{
    io_service io;
    tcp::socket client_sock1(io);
    tcp::socket client_sock2(io);
    tcp::acceptor acc(io, tcp::endpoint(tcp::v4(), 1234));


    //First Client 
    acc.accept(client_sock1);
    //  std::string s = boost::lexical_cast<std::string>(client_sock1.remote_endpoint());
    //  cout << s << endl;

    sendTo(client_sock1, "Waiting for opponent to Connect\n");

    acc.accept(client_sock2);
    //  s = boost::lexical_cast<std::string>(client_sock2.remote_endpoint());
    //  cout << s << endl;

    sendTo(client_sock1, "Starting Game...\n");
    sendTo(client_sock2, "Starting Game...\n");

    //Get The Field To Play Game from first Client
    sendTo(client_sock1, "Which Field You Wanna Play?\n");

    boost::asio::streambuf buff;
    string text = "";
    read_until(client_sock1, buff, "\n");
    text = buffer_cast<const char*>(buff.data());

    processAndRespond(client_sock2, text);


    cout << "Sending Turns\n";

    //set the turn
    sendTo(client_sock1, "true\n");
    sendTo(client_sock2, "false\n");

    loop = true;

    thread t1(receiveFrom, ref(client_sock1), ref(client_sock2));
    thread t2(receiveFrom, ref(client_sock2), ref(client_sock1));

    t1.join();
    t2.join();


    client_sock1.close();
    client_sock2.close();

    return 0;
}
