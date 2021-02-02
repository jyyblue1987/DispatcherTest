#include <iostream>
#include "linkedlist.h"
#include "events.h"
#include "structuretype.h"

using namespace std;

void printEvent(event e)
{
    cout << "Sector: " << e.getSector() << " Structure: " << e.getType() << endl;
}

void dumpList(linkedlist &ll)
{
    cout << "Dumping the linkedlist" << endl;
    while (!ll.isEmpty())
    {
        event result;
        ll.removeBack(result);
        printEvent(result);
    }
}

int main()
{
    linkedlist ll;
    event e1(1,WIND);
    event e2(2,WATER);

    cout << "dump list before adding" << endl;
    dumpList(ll);
    ll.insertFront(e1);
    dumpList(ll);
    ll.insertFront(e1);
    ll.insertFront(e2);
    dumpList(ll);

    return 0;
}
