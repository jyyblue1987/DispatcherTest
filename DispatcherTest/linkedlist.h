#pragma once
#include "events.h"

class linkedlist
{
	Node *head;
	Node *tail;
	
	void freeMemory();

public:
	linkedlist(void);
	~linkedlist(void);

	bool isEmpty();
	void insertFront(event &e);
	void removeBack(event &e);

};

