//Jose Rodriguez
//861090575
//5/5/2015

#include "lab5.h"

int main()
{
   BST<int> tree;
   map<int,int> my;
   tree.insert(50);
   tree.insert(20);
   tree.insert(60);
   tree.insert(40);
   tree.insert(10);
   tree.insert(35);
   tree.insert(70);
   tree.insert(45);
   
   int buffer[100];
   
   
   tree.displayMiniCover();
   tree.findSumPath(tree.root,80,buffer);
   tree.vertSum(tree.root,0,my);
}