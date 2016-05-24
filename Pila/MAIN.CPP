#include <iostream>
#include "Pila.h"

using namespace std;

int main()
{
    cout << "Hello !" << endl;
    Pila* miPila=new Pila;
    miPila->push(34);
    miPila->push(3);
    miPila->push(4);
    miPila->push(46);
    miPila->pop();
    miPila->imprimir();
    return 0;
}
