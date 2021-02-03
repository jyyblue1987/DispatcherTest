#include <stdio.h>
#include "events.h"


event::event(void)
{
	m_nSection = 0;
	m_nType = UNK;
}

event::event(int section, structure_type type)
{
	m_nSection = section;
	m_nType = type;
}

int event::getSector() 
{
	return m_nSection;
}

structure_type event::getType() 
{
	return m_nType;
}

void event::print1() 
{
	printf("Section = %d, Type = %d\n", m_nSection, m_nType);
}