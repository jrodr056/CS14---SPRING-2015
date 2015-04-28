//Jose Rodriguez
//861090575
//04/21/2015

#include <iostream>
#include <stack> 
#include "lab03.h"
using namespace std;

int main()
{
   stack<int> A;
   A.push(4);
   A.push(3);
   A.push(2);
   A.push(1);
   stack<int> B;
   stack<int> C;
   
   showTowerStates(4,A,B,C);
   cout<<C.top() << " " <<endl;
   C.pop();
   cout<<C.top() << " " <<endl;
   C.pop();
   cout<<C.top() << " " <<endl;
   C.pop();
   cout<<C.top() << " " <<endl;
   
   TwoStackFixed <int>m1 = TwoStackFixed<int>(3,3);
   
   m1.pushStack1(1);
   m1.pushStack1(2);
   m1.pushStack2(3);

   TwoStackOptimal<int>m2 = TwoStackOptimal<int>(6);
   
   m2.pushFlexStack1(1);
   m2.pushFlexStack1(1);
   m2.pushFlexStack1(1);
   m2.pushFlexStack1(1);
   m2.pushFlexStack2(1);
   m2.pushFlexStack2(1);
  
   m2.popFlexStack1();
   m2.popFlexStack1();
   m2.popFlexStack1();
   m2.popFlexStack1();
   m2.popFlexStack2();
   m2.popFlexStack2();
   
   
  
   m1.popStack1();
   m1.popStack1();
  
   

}