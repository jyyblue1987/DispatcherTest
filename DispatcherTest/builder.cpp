#include "builder.h"
#include <stdio.h>

builder::builder(void) {
	req = new linkedlist();
	st = new stack();
	m_nPrevSector = -1;
}

builder::~builder(void) {
	freeMemory();
}

void builder::freeMemory()
{
	if( req != NULL )
	{
		delete req;
		req = NULL;
	}

	if( st != NULL )
	{
		delete st;
		st = NULL;
	}

	m_nPrevSector = -1;
} 

void builder::addRequest(int sectorNum, structure_type type)
{
	// Each request specifies a sector and type of structure to build.
	event ev(sectorNum, type);

	// Whenever the builder receives a request, it should print out a message in the following format
	switch(type)
	{
	case WIND:		
		printf("Builder #%d: Received request to build a wind turbine in sector %d\n", m_nBuilderNum, sectorNum);
		break;
	case WATER:		
		printf("Builder #%d: Received request to build a water harvester in sector %d\n", m_nBuilderNum, sectorNum);
		break;
	case SOLAR:		
		printf("Builder #%d: Received request to build a solar energy collector in sector %d\n", m_nBuilderNum, sectorNum);
		break;
	}
	
	// The requests are stored in a linked list in the builder
	// New requests must be placed at the front of the list.	
	req->insertFront(ev);
}

bool builder::doCycle() 
{
	if( req->isEmpty() )
		return false;

	// the builder must process the oldest building request
	event ev;
	req->removeBack(ev);

	int sector = ev.getSector();

	if( m_nPrevSector != ev.getSector() )	// Otherwise, the builder must travel to the new sector first.
	{
		// Moving sector
		event ev1(sector, UNK);
		st->push(ev1);

		printf("Builder #%d: Moving to sector %d\n", m_nBuilderNum, sector);
		m_nPrevSector = sector;
	}
 
	// Otherwise, the builder must travel to the new sector first.
	// and create that structure.
	st->push(ev);
	switch(ev.getType())
	{
	case WIND:		
		printf("Builder #%d: Building a wind turbine in sector %d\n", m_nBuilderNum, sector);
		break;
	case WATER:		
		printf("Builder #%d: Building a water harvester in sector %d\n", m_nBuilderNum, sector);
		break;
	case SOLAR:		
		printf("Builder #%d: Building a solar energy collector in sector %d\n", m_nBuilderNum, sector);
		break;

	}

	return true;
}

void builder::returnHome() 
{
	// When this happens, 
	// the builder should backtrack through the list of structures that it built, in reverse order.
	while(st->isEmpty() == false)
	{
		event *ev = st->pop();

		int sector = ev->getSector();

		switch(ev->getType())
		{
		case WIND:		
			printf("Builder #%d: Connected to wind turbine in sector %d\n", m_nBuilderNum, sector);
			break;
		case WATER:		
			printf("Builder #%d: Connected to water harvester in sector %d\n", m_nBuilderNum, sector);
			break;
		case SOLAR:		
			printf("Builder #%d: Connected to solar energy collector in sector %d\n", m_nBuilderNum, sector);
			break;
		case UNK:		
			printf("Builder #%d: Moving to sector %d\n", m_nBuilderNum, sector);
			break;

		}
		delete ev;
	}
}
void builder::setBuilderNum(int num)
{
	m_nBuilderNum = num;
}