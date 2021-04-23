#ifndef FIELD1_H
#define FIELD1_H

#include "field.h"

class Field1 : public Field
{


public:
	Field1();
	void updateBoard();
	bool checkForWining(int player);
	bool setPlace(int, int);

	bool checkForDraw();
	int getInput(int player);


};

#endif
