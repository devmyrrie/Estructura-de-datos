#include <iostream>



#include "List.h"
#include "Node.h"
using namespace std;

int main()
{
    cout << "Hello !" << endl;
    List<int> lista;
    lista.add(3);
    lista.add(32);
    lista.add(322);
    lista.erase(32);
    lista.print();

    return 0;
}
