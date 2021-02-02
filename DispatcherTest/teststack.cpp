#include <iostream>
#include "stack.h"
#include "events.h"
#include "structuretype.h"

using namespace std;

void dumpStack(stack &s)
{
    cout << "Dumping the stack" << endl;
    while (!s.isEmpty())
    {
        event *result = s.pop();
        cout << "Value: ";
        result->print1();
    }
}

int main()
{
    stack* s = new stack(100);
    event e1(1,WIND);
    event e2(2,SOLAR);
    event e3(3,WATER);
    event* ePtr;

    s->push(e1);
    dumpStack(*s);
    s->push(e2);
    s->push(e3);
    dumpStack(*s);

    delete s;
}
