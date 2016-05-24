#ifndef PILA_H
#define PILA_H


class Pila {
    public:
        /** Default constructor */
        Pila();
        typedef struct node {
            int data;
            node* next;
            }* nodePtr;

        struct node* crear_celda(int value);//Crea una celda tipo node  con un valor.
        void push(int value);//Mete un valor llamado value.
        void pop();//Saca el ultimo valor que fue ingresado.
        void pop(int value);//Saca este valor
        bool existe(int x);
        void eliminar_pila();
        void imprimir();
        int tamano();
        nodePtr celda_arriba;//Es el que esta mas arriba de todo

    private:
    };

#endif // PILA_H
