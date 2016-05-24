#include <iostream>
#include "Cola.h"
using namespace std;

int main()
{
    cout << "Hello !" << endl;

    Cola<int> x;
    for(int i=0; i<10; ++i)
    {
        x.push(i);
        x.consult();
        x.pop();
    }
    return 0;
}
