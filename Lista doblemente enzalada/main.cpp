#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    cout << "Hello!" << endl;
    List<int> x;
    x.add(44);
    x.add(343);
    x.add(45254);
    x.erase(45254);
    x.print();
    //Ver en el depuradors poirque despues de 0, se me mete al destrucotr de list y falla

    return 0;
}
