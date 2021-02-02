#ifndef BUILDER_H
#define BUILDER_H

#include "structuretype.h"
class builder
{
private:

public:
    // The requests are stored in a linked list in the builder
    // New requests must be placed at the front of the list.
    // Each request specifies a sector and type of structure to build.
    void addRequest(int sectorNum, structure_type type);
    // When doCycle() is called on the builder, the builder must process the oldest building
    // request and create that structure.
    // Note that since all requests are added to the front of the list,
    // the oldest request is at the back of the list so the builder should
    // remove items from the back of the list.
    bool doCycle();
    
	void returnHome();
    void setBuilderNum(int num);
};

#endif