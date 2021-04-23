#pragma once
#ifndef FIELD4_H
#define FIELD4_H

#include "field.h"


class Field4 : public Field
{

public:

    Field4();
    void updateBoard();
    bool checkForWining(int player);
    bool setPlace(int, int);

    bool checkForDraw();
    int getInput(int player);


};



#endif
#pragma once
