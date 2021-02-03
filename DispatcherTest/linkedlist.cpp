#include <stdlib.h>

#include "linkedlist.h"


linkedlist::linkedlist(void)
{
	head = NULL;	
	tail = NULL;	
}

linkedlist::~linkedlist(void) {
	freeMemory();
}

void linkedlist::freeMemory()
{
	Node *cur = NULL;
	Node *prev = NULL;

	cur = tail;
	while(cur) {
		prev = cur->prev;
		free(cur);		
		cur = prev;
	}
	head = NULL;	
	tail = NULL;	
}

bool linkedlist::isEmpty()
{
	return head == NULL;
}

void linkedlist::insertFront(event &e)
{
	Node *node = (Node *) malloc(sizeof(Node));
	node->sector = e.getSector();
	node->type = e.getType();	
	node->prev = NULL;

	if( head == NULL )
		tail = node;
	else
		head->prev = node;

	head = node;		
}

void linkedlist::removeBack(event &e)
{
	if( tail == NULL )
		return;

	e.m_nSection = tail->sector;
	e.m_nType = tail->type;

	Node *prev = tail->prev;

	free(tail);
	tail = prev;
	if( tail == NULL )
		head = NULL;
}