#ifndef FIELD2_H
#define FIELD2_H

#include "field.h"

class Field2 : public Field
{

public:

    Field2();
    void updateBoard();
    bool checkForWining(int player);
    bool setPlace(int, int);

    bool checkForDraw();
    int getInput(int player);


};


#endif#pragma once
