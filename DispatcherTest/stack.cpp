#include <stdlib.h>
#include "stack.h"


stack::stack(void)
{
}

stack::stack(int count)
{
}

stack::~stack(void) {
	freeMemory();
}

void stack::freeMemory()
{
	Node *cur = NULL;
	Node *prev = NULL;

	cur = tail;
	while(cur) {
		prev = cur->prev;
		free(cur);		
		cur = prev;
	}
	tail = NULL;		
}

bool stack::isEmpty()
{
	return tail == NULL;
}

void stack::push(event &e)
{
	Node *node = (Node *) malloc(sizeof(Node));
	node->sector = e.getSector();
	node->type = e.getType();	
	node->prev = tail;

	tail = node;	
}

event* stack::pop() 
{
	if( tail == NULL )
		return NULL;

	event *ev = new event(tail->sector, tail->type);

	Node *prev = tail->prev;
	free(tail);
	tail = prev;

	return ev;
}
