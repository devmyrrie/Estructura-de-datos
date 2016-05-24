#ifndef LIST_H
#define LIST_H
#include "Node.h"

//Lista ordenada y no ordenada (depende de lo que ingrese usuario)
template <typename data_type >
class List
{
    //Variables globales.
    typedef Node<data_type>* Nodo;

private:
    Node<data_type>* first;
    Node<data_type>* last;

public:
    List();
    ~List();

    void add(data_type); //Agregar ordenadamente
    void print();
    void erase(data_type);

private:
};


template <typename data_type >
List<data_type>::List()
{
    first=0;
    last=0;

}

template <typename data_type >
List<data_type>::~List()
{
//    std::cout<<"entre"<<std::endl;
//    Nodo iterador= first;
//    data_type dat = 0;
//    while(iterador !=0)
//    {
//        dat =iterador->data;
//        erase(dat);
//        iterador=iterador->next;
//
    //
//    }
    Nodo iterador= first;
    while(iterador !=0)
    {
        Nodo aux = first;
        first=first->next;
        delete aux;
        aux= 0;
        iterador=iterador->next;

    }

}

template <typename data_type >
void List<data_type>::add(data_type e)
{
    Nodo cell = new Node<data_type>();
    cell->data=e;
    if(first==0)
    {
        last=first=cell;
    }
    else
    {
        if(e<first->data)
        {
            cell->next = first;

            first->prev =cell;
            first=cell;
            if(first->next == 0)
            {

                last=first;
            }
        }
        else
        {

            Nodo iterador = first;
            while(iterador->next != 0 && iterador->next->data < e)
            {
                iterador=iterador->next;

            }
            cell->next=iterador->next;
            iterador->next=cell;
            cell->prev=iterador;
            if(cell->next != 0)
            {
                cell->next->prev =cell;


            }
            else
            {
                last=cell;
            }
        }

    }
}


template <typename data_type >
void List<data_type>::print()
{
    //Imprime alrevez
    Nodo iterador = last;
    while(iterador!=0)
    {
        std::cout<<iterador->data<<std::endl;
        iterador=iterador->prev;
    }

}

template <typename data_type >
void List<data_type>::erase(data_type e)
{

    if(first !=0)
    {
        if(first->data == e)
        {
            Nodo aux = first;
            first = first->next;
            if(first != 0)
            {
                first->prev = 0;
                if(first->next == 0)
                {
                    last= first; //ahora last va aser el first
                }
            }
            else
            {
                last=0;
            }
            delete aux;
            aux = 0;

        }
        else
        {
            Nodo iterador = first;
            while(iterador->next != 0 && iterador->next->data != e)
            {
                iterador = iterador->next;

            }
            Nodo aux = iterador->next;
            if(aux != 0)  //hay algo que eliminar
            {
                iterador->next = aux->next;
                if(aux->next != 0)
                {
                    aux->next->prev =iterador;
                }
                else
                {
                    last=aux->prev; // el que se va a borrar es el ultimo, por eso lat cambia al penultimo
                }
                delete aux;
                aux =0;
            }


        }


    }


}






#endif // LIST_H
