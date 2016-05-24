#ifndef LIST_H
#define LIST_H
#include "Node.h"

using namespace std;
//Lista ordenada y no ordenada (depende de lo que ingrese usuario)
template <typename data_type >
class List
{
    //Variables globales.

private:
    Node<data_type>* first;
    Node<data_type>* last;

public:
    List();
    ~List();

    void add(data_type); //Agregar ordenadamente
    void print();
    void erase(data_type);


};

template <typename data_type>
List<data_type>::List()
{
    first = 0;
}

template <typename data_type>
List<data_type>::~List()
{

}

template <typename data_type>
void List<data_type>::add(data_type data)
{
    Node<data_type>* cell = new Node<data_type>;
    cell->data = data;
    if(first == 0)
    {
        first=cell;
        last= cell;
        first->next=first;
    }
    else
    {
        Node<data_type>* iterator = first;
        while(iterator->next != first && iterator->next->data < data)
        {
            iterator = iterator->next;




        }
        cell->next =iterator->next;
        if(cell->next ==first){//si el sig del celda es la cabeza, esta celda sria el ultimo
                last=cell;
            }
        iterator->next=cell;

    }
}

template <typename data_type>
void List<data_type>::print()
{
    //Imprime desde el primero hasta el ultimo, aunque sea circular, se detinen antes de enciclarse.
    if(first != 0)
    {
        Node<data_type>* iterator = first;
        bool stop =false;
        while(iterator != 0 && !stop)
        {
            std::cout<<iterator->data<<"\n";
            if( iterator->next == first)
            {
                stop=true;
            }
            iterator = iterator->next;

        }

    }

}




template <typename data_type>
void List<data_type>::erase(data_type data)
{

    if(first != 0)
    {
        if(first->data == data)
        {
            Node<data_type>* aux = first;
            first = first->next;
            delete aux;
            if(first != 0)
            {
                last->next = first;

            }

        }
        else
        {
            Node<data_type>* iterator = first ;
            Node<data_type>* aux =  new Node<data_type>();
            aux = 0;
            bool found = false;
            while(iterator->next != 0 && !found)
            {
                if(iterator->next->data == data )
                {
                    aux = iterator->next;
                    found = true;
                }
                else
                {
                    iterator = iterator ->next;

                }
            }
            iterator->next = aux->next;
            if(aux->next == 0)
            {
                iterator->next =first;
                last=iterator;


            }
            delete aux;
            aux=0;

        }
    }

}





#endif // LIST_H
