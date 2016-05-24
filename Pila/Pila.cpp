#include "Pila.h"
#include <iostream>
using namespace std;



Pila::Pila()
    :celda_arriba(NULL) {
    //Inicializamos  la cabeza en NULL
    }

Pila:: nodePtr  Pila::crear_celda(int value) {
    nodePtr nueva = new node;
    nueva->data=value;
    nueva->next=NULL;
    return  nueva;
    }



void Pila::push(int value=0) {
    nodePtr celda = crear_celda(value);
    if(celda_arriba == NULL) {
            celda_arriba=celda;
            }
    else {
            nodePtr aux = celda_arriba;
            celda_arriba =celda;
            celda_arriba -> next = aux;
            aux=NULL;//Verdad que aqui se tiene que poner = NULL sin el delete, ya que la celda quu apunta aux se iria...?
            }
    }


bool Pila::existe(int x) {
    nodePtr iterador= celda_arriba;
    bool ex =false;
    do {
            if(iterador != NULL) {
                    ex = (( iterador->data)==x? true:false);
                    iterador=iterador->next;

                    }

            }
    while(iterador != NULL && ex==false);


    return ex;
    }

void Pila::pop() {
    if(celda_arriba == NULL) {
            cout<<"Lista vacia"<<endl;
            }
    else {
            nodePtr aux =celda_arriba;
            celda_arriba=celda_arriba-> next;
            delete aux;
            aux=NULL;
            }

    }

void Pila::pop(int x) {
    if(celda_arriba == NULL) {
            cout<<"Lista vacia"<<endl;
            }
    else {
            nodePtr iterador = celda_arriba;
            if(  existe(x) ) {
                    while( (iterador != NULL )&& (iterador -> data) != x) {
                            pop();
                            iterador=iterador->next;
                            }

                    pop();
                    }

            }

    }

void Pila::eliminar_pila() {
    nodePtr iterador = celda_arriba;
    do {
            if(iterador!= NULL) {
                    pop();
                    iterador=iterador->next;
                    }
            }
    while(iterador != NULL);


    }


void Pila::imprimir() {
    nodePtr iterador = celda_arriba;
    do {
            if(iterador !=NULL) {
                    cout <<iterador->data<<endl;
                    iterador=iterador->next;
                    }
            else

                    {
                    cout<< "iterador esta en null"<<endl;
                    }

            }
    while(iterador != NULL);
    iterador=NULL;
    }


int Pila::tamano() {
    int contador=0;
    nodePtr iterador = celda_arriba;
    do {
            if(iterador !=NULL) {
                    contador++;
                    iterador=iterador->next;
                    }
            }
    while(iterador != NULL);
    iterador=NULL;
    return   contador;

    }
