#ifndef COLA_H
#define COLA_H
#include "Node.h"
using namespace std;

template <typename data_type>
class Cola
{
private:
    Node<data_type>* front;
    Node<data_type>* back;

public:
    Cola() ;
    ~Cola() ;

    void push(data_type&);
    void pop();
    void consult();


};


template <typename data_type>
Cola<data_type>::Cola()
{
    front=0;
    back=0;
}


template <typename data_type>
Cola<data_type>::~Cola()
{
    while(front!=0)
    {
        pop();
    }
}


template <typename data_type>
void Cola<data_type>::push(data_type& e)
{

    Node<data_type>* cell = new Node<data_type>();
    cell->data=e;

    if(front == 0)
    {
        back=front=cell;
    }
    else
    {
        back->next= cell;
        back=cell;
    }
}


template <typename data_type>
void Cola<data_type>::pop()
{
    Node<data_type>* aux = front;
    front=front->next;
    delete aux;
    aux=0;
}



template <typename data_type>
void Cola<data_type>::consult()
{
    if(front!=0)
    {
        cout<<"Data : "<< front->data<<endl;

    }
}




#endif // COLA_H
