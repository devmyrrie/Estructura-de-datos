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

public:
    List();
    ~List();

    void add(data_type); //Agregar ordenadamente
    void print();
    void add_r(data_type); //Averiguar si se puede hacer recursivo pero ordenado
    void erase(data_type);
    void  find(data_type);

private:
    void add_r(Node<data_type>**, data_type);
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

    }
    else
    {
        Node<data_type>* iterator = first;
        while(iterator->next != 0 && iterator->next->data < data)
        {
            iterator = iterator->next;

        }
        cell->next =iterator->next;
        iterator->next=cell;
    }
}

template <typename data_type>
void List<data_type>::print()
{
    if(first != 0)
    {
        Node<data_type>* iterator = first;
        while(iterator != 0)
        {
            std::cout<<iterator->data<<"\n";
            iterator = iterator->next;
        }

    }

}

template <typename data_type>
void List<data_type>::add_r(data_type data)
{
    add_r(&first,data);

}

template <typename data_type>
void List<data_type>::find(data_type data)
{
    bool found=false;
    if(first != 0)
    {
        if(first->data == data)
        {
            cout<<"Dato encontrado :"<<data<<endl;
            found =true;
        }
        else
        {
            Node<data_type>* iterator  = first;
            while(iterator->next != 0 && !found)
            {
                if(iterator->next->data == data)
                {
                    found=true;


                }
                else
                {
                    iterator=iterator->next;


                }


            }
            if(found ==true)
            {
                Node<data_type>* aux  = iterator->next;
                iterator->next=iterator->next->next;

                aux->next=first;
                first=aux;


            }


        }

    }




}


template <typename data_type>
void List<data_type>::add_r(Node<data_type>**  ptr , data_type data)
{
    if(*ptr == 0)
    {
        Node<data_type>* cell = new Node<data_type>();
        cell->data = data;
        *ptr =cell;
    }
    else
    {
        add_r( & ( (*ptr)->next) ,  data);

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
            delete aux;
            aux=0;
        }
    }

}





#endif // LIST_H
