#pragma once
#include "structuretype.h"

#define NULL 0

struct Node {
	int sector;
	structure_type type;	
	Node *prev;
};


class event
{
public:
	int m_nSection;
	structure_type m_nType;

	event(void);
	event(int section, structure_type type);

	int getSector(); 
	structure_type getType(); 
	void print1();
};

