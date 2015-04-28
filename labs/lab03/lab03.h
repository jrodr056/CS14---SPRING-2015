//Jose Rodriguez
//861090575
//04/21/2015

#include <iostream>
#include <stack> 
#include <array>
using namespace std;

template <typename Type>
class TwoStackFixed
{

    private:
    Type *myArray;
    
    int sizeStack1;
    int sizeStack2;
    int mySize;
    int end;
    int begin;
    int stackSize;
    
    public:
    
    TwoStackFixed(int size, int maxtop )
    {
        myArray = new Type[size];
        end = size;
        sizeStack1 = 0;
        sizeStack2 = 0;
        mySize = size;
        stackSize = maxtop;
        begin = -1;
    }
    bool isFullStack1()
    {
        if(sizeStack1<=stackSize && begin < end-1)
        return false;

        else 
        return true;
        
    }
    
     bool isFullStack2()
    {
        if(sizeStack2 <=stackSize && begin < end-1)
        return false;
        else
        return true;
    }
    
    
    void pushStack1(Type value)
    {
        sizeStack1+=1;
        
        if(isFullStack1()==false)
        {
            begin+=1;
            myArray[begin] = value;
        }
        else
        {
            cout<<"stack overflow"<<endl;
            exit(1);
        }
        
        
    }
    
    void pushStack2(Type value)
    {
        sizeStack2+=1;
        
        if(isFullStack2()==false)
        {
            end-=1;
            myArray[end] = value;
        }
        else
        {
            cout<<"stack overflow"<<endl;
            exit(1);
        }
    }
    
    bool isEmptyStack1()
    {
        if(sizeStack1>=0)
        return false;
        else
        return true;
    }
    
     bool isEmptyStack2()
    {
        if(sizeStack2>=0)
        return false;
        else
        return true;
    }
    
    Type popStack1()
    {
        sizeStack1-=1;
        
        if(isEmptyStack1()==false && begin>=0)
        {
            Type thing = myArray[begin];
            begin-=1;
            return thing; 
        }
        
        else
        {
            cout<<"Stack underflow"<<endl;
            exit(1);
        }
        
    }
    
     Type popStack2()
    {
        sizeStack2-=1;
        
        if(isEmptyStack1()==false && end<mySize)
        {
            Type thing = myArray[begin];
            end+=1;
            return thing; 
        }
        
        else
        {
            cout<<"Stack underflow"<<endl;
            exit(1);
        }
        
    }
    
};
template <typename Type>
class TwoStackOptimal
{
    private:
    Type *myArray;
    int begin;
    int end;
    int mySize;
    public:
    
    TwoStackOptimal(int size)
    {
        myArray = new Type[size];
        mySize = size;
        begin = -1;
        end = size;
    }
    
    bool isFullStack1() //checks for at least one space
    {
        if(begin < end - 1)
        return false;
        else
        return true;
        
    }
    bool isFullStack2() //checks for at least one space
    {
        if(begin < end - 1)
        return false;
        else
        return true;
        
    }
    void pushFlexStack1(Type value)
    {
        if(isFullStack1()==false)
        {
            begin++;
            myArray[begin] = value;
            
        }
        
        else
        {
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
        
        
    }
    
     void pushFlexStack2(Type value)
    {
        if(isFullStack2()==false)
        {
            end--;
            myArray[end] = value;
            
        }
        
        else
        {
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
        
        
    }
    
    bool isEmptyStack1()
    {
        if(begin>=0)
        return false;
        else
        return true;
    }
    
     bool isEmptyStack2()
    {
        if(end < mySize)
        return false;
        else
        return true;
    }
    
    Type popFlexStack1()
    {
        if(isEmptyStack1()==false)
        {
            Type thing = myArray[begin];
            begin--;
            return thing;
            
        }
        else
        {
            cout<<"stack underflow"<<endl;
            exit(1);
            
        }
        
    }
    
    Type popFlexStack2()
    {
        if(isEmptyStack2()==false)
        {
             Type thing = myArray[end];
             end++;
             return thing;
        }
       else
       {
           cout << "Stack UnderFlow";
           exit(1);
       }

        
    }
    
    
};

template <typename Type>
void showTowerStates(int n, stack<Type>& A,stack<Type>& B, stack<Type>& C)
{
    
    
    if(n == 1)
    {
        if(!A.empty())
        {
            cout<<"Moved " << A.top() <<endl;
            C.push(A.top());
            A.pop();
        }
       
    }
   else
   {  
        showTowerStates(n-1,A,C,B);
        if(!A.empty())
        {
            cout<<"Moved "<< A.top()<<endl;
            C.push(A.top());
            A.pop();
        }
 
        showTowerStates(n-1,B,A,C);
   }    
}