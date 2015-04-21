#ifndef LAB2_H
#define LAB2_H
#include <forward_list>
#include <iostream>
using namespace std;

template<class Type> class newNode
{
    public:
    Type data;

    newNode<Type> *next;

    newNode<Type>( Type data ) : data(data), next(0) {}
    

};



template<class Type> class List
{
   public:
   newNode<Type>* head;
   newNode<Type>* tail;
   List();
   List<Type> elementSwap(List<Type> lst, int pos);
   void push_back(Type value);
   void display() const;
};

#endif