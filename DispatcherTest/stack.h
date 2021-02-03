#pragma once
#include "events.h"
class stack
{
	Node *tail;

	void freeMemory();

public:
	stack(void);
	stack(int count);
	~stack(void);

	bool isEmpty();
	void push(event &e);
	event* pop(); 	

};

