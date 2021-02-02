#pragma once
#include "structuretype.h"

class event
{
public:
	event(void);
	event(int section, structure_type type);

	int getSector(); 
	structure_type getType(); 
	void print1();
};

