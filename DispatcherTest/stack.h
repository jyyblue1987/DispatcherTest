#pragma once
#include "events.h"
class stack
{
public:
	stack(void);
	stack(int count);

	bool isEmpty();
	void push(event e);
	event* pop(); 	

};

