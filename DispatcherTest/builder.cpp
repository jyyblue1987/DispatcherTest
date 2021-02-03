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
	event ev(sectorNum, type);
	
	req->insertFront(ev);
}

bool builder::doCycle() 
{
	if( req->isEmpty() )
		return false;

	event ev;
	req->removeBack(ev);

	int sector = ev.getSector();

	if( m_nPrevSector != ev.getSector() )
	{
		// Moving sector
		event ev1(sector, UNK);
		st->push(ev1);

		printf("Builder #%d: Moving to sector %d\n", m_nBuilderNum, sector);
		m_nPrevSector = sector;
	}

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
	while(st->isEmpty())
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
			printf("Builder #%d: Moving to sector %d", m_nBuilderNum, sector);
			break;

		}
		delete ev;
	}
}
void builder::setBuilderNum(int num)
{
	m_nBuilderNum = num;
}