#pragma once
#ifndef FIELD3_H
#define FIELD3_H

#include "field.h"



class Field3 : public Field
{

public:

    Field3();
    void updateBoard();
    bool checkForWining(int player);
    bool setPlace(int, int);

    bool checkForDraw();
    int getInput(int player);


};








#endif
#pragma once
