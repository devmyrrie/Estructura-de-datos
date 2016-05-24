#include <iostream>
#include "arbol.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    arbol <int> x;

    x.insertar_nodo(50);
    x.insertar_nodo(25);
    x.insertar_nodo(75);
    x.insertar_nodo(12);
    x.insertar_nodo(33);
    x.insertar_nodo(67);
    x.insertar_nodo(88);
    x.insertar_nodo(6);
    x.insertar_nodo(13);
    x.insertar_nodo(68);
    //  x.descendente();
    //x.ascendente();
    //x.recorrer_postorden();
    x.recorrer_preorden();
    //x.recorrer_inorden();
    cout << endl;
    x.borrar_nodo(6);
    cout << endl;
    x.recorrer_preorden();
    //x.recorrer_inorden();
    return 0;
}
