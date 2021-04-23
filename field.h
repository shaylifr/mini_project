//#pragma once
#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

class Field
{

protected:
    int BOARD_SIZE;
    int boardRow;
    int boardCol;

    std::vector<int> board;

public:
    Field() {}
    virtual void updateBoard() = 0;
    virtual bool checkForWining(int player) = 0;
    virtual bool setPlace(int place, int p) = 0;
    virtual bool checkForDraw() = 0;
    virtual int getInput(int player) = 0;
};



#endif
