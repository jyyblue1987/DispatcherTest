#pragma once
#include "events.h"
class linkedlist
{
public:
	linkedlist(void);

	bool isEmpty();
	void insertFront(event e);
	void removeBack(event e);

};

