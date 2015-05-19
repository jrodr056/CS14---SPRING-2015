//Jose Rodriguez
//861090575
//5/19/2015


#include<list>
#include<vector>
#include <array>
#include <iostream>

using namespace std;

template<typename L>
void selectionsort(L &l)
{
   int count = 0;
   int copies = 0;
    cout<<"pre:  ";
    
    for(auto it = l.begin(); it!= l.end(); it++)
    {
        cout << *it << " ";
    
    }
    
    cout<<endl;
    
    
    
    
   
   
    //code to sort Type L
    
    
    using std::swap;
    auto min = l.begin();
    
    for(auto k = l.begin(); k!= l.end(); k++)
    {
        min = k;
        
        
        for(auto p = k; p!= l.end(); p++)
        {
            if(*p < *k)
            {
              min = p;
            }
            
        
        }
        if(min!=k)
        {
         swap(*k,*min);
         count++;
        }
    }

    
    
    cout<<"post: ";
    for(auto m = l.begin(); m!=l.end(); m++)
    {
        cout<<*m<< " ";
    }
    cout<<endl;
    cout<<copies <<" copies and " <<count<< " moves"<<endl;
    
    
}

//Question 2: Stability
// Part A: My selectionsort function is stable because it to does not swap two elements if they are equal.
//A simple change in comparison from <= to < makes it stable.

//Part B: see main