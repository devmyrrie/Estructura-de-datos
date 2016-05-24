#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

template <typename data_type> class arbol;


template <typename data_type>
class nodo_arbol
{
    friend class arbol<data_type>;

    private:
        data_type data;
        nodo_arbol* der;
        nodo_arbol* izq;

    public:

    nodo_arbol()
    :der(0),izq(0){};

    nodo_arbol(data_type e)
    :der(0),izq(0),data(e){};
};

#endif // NODO_ARBOL_H
