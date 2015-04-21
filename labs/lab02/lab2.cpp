//Jose Rodriguez
//861090575
//04/14/2015
#include <forward_list>
#include <iostream>
#include "lab2.h"
using namespace std;

template<class Type>
List<Type>::List()
{
    head=0;
    tail=0;
}

template<class Type>
void List<Type>::push_back(Type value)
{
    newNode<Type>* tmp = new newNode<Type>(value);
    if(head==0)
    {
        head = tmp;
        tail = tmp;
            
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}

bool isPrime(int i)
{
    
    if(i==0 || i==1)
    return false;
    
    for(int j = 2; j<=100; j++)
    {
        if(i%j==0 && j!=i)
        {
            return false;
        }
        
        
    }
    
    return true;
    
    
}

int primeCount(forward_list<int> lst)
{
    bool num =0;
    forward_list<int>::iterator i;
    i = lst.begin();
    
    if(i!=lst.end())
    {
        bool taco = isPrime(*i);
        if(taco==true)
        {
            
            num = 1;
        }
        lst.pop_front();
        return num + primeCount(lst);
    }
    
    return 0;
}

template<class Type>
List<Type> List<Type>::elementSwap(List<Type> lst, int pos)
{
    
    newNode<Type>* prev = lst.head;
    if(prev->next==0)
    return lst;
    newNode<Type>* curr = lst.head->next;
    
    
    int count = 1;
    while(prev!=0 && curr!=0)
    {
        if(pos==0)
        {
            if(curr->next==0)
            return lst;
            prev->next = curr->next;
            curr->next = prev;
            lst.head = curr;
            break;
            
        }        
        else if(count == pos)
        {
            if(curr->next==0)
            return lst;
            
            else if(curr->next==lst.tail)
            {
                prev->next = lst.tail;
                lst.tail->next = curr;
                curr->next = 0;
                lst.tail = curr;
                
            }
            else
            {
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev = prev->next;
                prev->next = curr;
                
                break;
            }
        }
        
        count++;
        prev = prev->next;
        curr = curr ->next;
    }
    return lst;
}

template<class Type>
void List<Type>::display() const
{
    newNode<Type>* curr;
    for(curr=head; curr!=0; curr=curr->next)
    {
        cout<<curr-> data;
        if(curr->next!=0)
        cout<<" ";
    }
    
    
}


template<typename Type>
forward_list <Type> listCopy( forward_list <Type> L, forward_list <Type>P) 
{
    typename forward_list<Type>::iterator i;
     
    for(i=L.begin(); i!=L.end(); i++)
    {
        P.push_front(*i);
        
    }
    return P;
    
}

template<typename Type>
void printLots (forward_list<Type> L,forward_list <int> P)
{
    typename forward_list<Type>::iterator i,k;
    int count=0;
    
    for(i=L.begin(); i!=L.end(); i++)
    {
        for(k = P.begin(); k!=P.end(); k++)
        {
          if(*k==count)
          {
            cout<<*i;
          }
        }
        count++;
    }
    
    
}