#ifndef NODE_H
#define NODE_H

template <typename data_type>
class List;

template <typename data_type>
class Node
{
    //Variables Globales
private:
    data_type data;
    Node<data_type>* next;

public:
    Node();
    friend class List<data_type>;
};

template<typename data_type>
Node<data_type>::Node()
{
    next=0;
}



#endif // NODE_H
