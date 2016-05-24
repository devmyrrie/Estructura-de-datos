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
    lista.add(34);
    lista.add(54);

    lista.find(54);
    lista.print();
    return 0;
}
