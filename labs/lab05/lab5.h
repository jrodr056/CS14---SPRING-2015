#ifndef BST_H
#define BST_H
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;

#define nil 0

template <typename Value>
class BST
{
    class Node 
    { 
        public:
        Value value;
        Node* left;
        Node* right;
        Node( const Value v = Value())
        : value(v),left(nil),right(nil)
        {}
        
        Value& content() {return value;}
        bool isInternal() { return left != nil && right != nil; }
        bool isExternal() { return left != nil || right != nil; }
        bool isLeaf() { return left == nil && right == nil; }
        
        int height() 
        {
            if(this==nil)
            return 0;
            else if(this->isLeaf())
            return 1;
            
            else if(this!=nil)
            {
                int heightleft = this->left->height();
                int heightright = this->right->height() ;
                
                if(heightleft >= heightright)
                return 1 + heightleft;
                else
                return 1 + heightright;
                
                
            }
             return 0;
        }
        
        int size() 
        {
            if(this==nil)
            return 0;
            
            else if(this->isLeaf())
            return 1;
    
            else if(this!=nil)
            {
                return 1 + this->left->size() + this->right->size();
            }
        
            else
            return 0;
        }
        
        
        void inorder()const 
        {
            if(this!=nil)
            {
                this->left->inorder();
                cout<<this->value <<endl;
                this->right->inorder();
            }
        }
        
        void preorder()const 
        {
            if(this!=nil)
            {
                cout<<this->value <<endl;
                this->left->preorder();
                this->right->preorder();
            }
        }
        
        void postorder()
        {
             if(this!=nil)
            {
                this->left->postorder();
                this->right->postorder();
                cout<<this->value <<endl;
            }
        }
        
        void helpSearch ( Value x , bool &isthere)
        {
            
            if(this!=nil)
            {
                
                this->left->helpSearch(x,isthere);
                
                this->right->helpSearch(x,isthere);
               
               if(this->value==x)
               isthere = true;
            }
            
            
        
        }
        
        void help(vector<Node*> &mine)
        {
            
            if(this!=nil)
            {
                this->left->help(mine);
                 
                mine.push_back(this);
                 
                this->right->help(mine);


            }
            
            
            
        }
        
        void minCover(int &count)
        {
            
            if(this!=nil)
            {
                this->left->minCover(count);
                if(this->isLeaf()==false)
                {
                    count+=1;
                    cout<<this->value<<" ";
                }
                this->right->minCover(count);
            }
        
        }
        
    };  //end of Node class
    

    
    public:
    Node* root;
    int count;
    
    
    int size()
    {
        return root->size();
    }
    
    bool empty() { return size() == 0; }
    
    void print_node( const Node* n )
    {
        cout<<n->value<<endl;
        
    }

    bool search ( Value x )
    {
        bool isthere = false;
        root->helpSearch(x,isthere);
        
        if(isthere == true)
        return true;
        
        else
        return false;
    }
    
  
    
    void preorder()const
    {
          
         root->preorder();
    }
    
    void postorder()const
    {
         root->postorder();
    }
    
    void inorder()const 
    {
        root->inorder();
    }

    Value& operator[] (int n)
    {
        
        
        vector<Node*> inode;
        
        if(n>=root->size() || n<0)
        {    
            cout<<"Out of bounds"<<endl;
            exit(0);
        }
        
         root->help(inode);
         
         return inode.at(n)->value;
         
    }
    
    
    void displayMiniCover()
    {
        cout<<"Part 1"<<endl;
        int count=0;
        root->left->minCover(count);
        root->right->minCover(count);
        cout<<endl;
        cout<<count<<endl;
        
    }
    void findSumPathhelp(Node* n, int currSum , int subSum,int path, int buffer[])
    {
        if(n==nil)
        return;
        
        buffer[path] = n->value;
        path++;
        currSum +=n->value;
        
        if(n->isLeaf() && currSum == subSum);
        {
            printPath(buffer,path);
            return;
        }
        if(n->left!=nil)
        findSumPathhelp(n->left,currSum,subSum,path,buffer);
        
        if(n->right != nil)
        findSumPathhelp(n->right,currSum,subSum,path,buffer);
    }
    
    void findSumPath(Node* n, int sum, int buffer[])
    {
        cout<<"Part 2"<<endl;
        findSumPathhelp(root, 0, sum, 0, buffer);
        cout<<endl;
    
    }
    void printPath(int buffer[],int path)
    {
        list<int> L;
        
        for(int i = 0; i < path; i++)
        L.push_back(buffer[i]);
        L.sort();
        list<int>::iterator j;
        
        j=L.begin(); 
        while( j!=L.end())
        {
            cout<<*j<< " ";
            j++;
        }
    }
    void vertSumhelp(Node* node, int hd, std::map<int, int>& m)
    {
        
        if(node)
      {
        m[hd] = m[hd] + node->value;
        vertSumhelp(node->left, hd - 1, m);
        vertSumhelp(node->right, hd + 1, m);
      }
 
    }

    
    void vertSum(Node* node, int hd, std::map<int, int>& m)
    {
        if(root==nil)
        return;
        
        vertSumhelp(root, 0, m);
        cout<<"Part 3"<<endl;
        for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) 
        {
          cout <<it->second<< "  ";     
        }
        cout<<endl;
        

    }
    //git push -u origin master
 //git commit -m "First commit";
    
    BST() : root(nil), count(0){}
    
    
  void insert( Value X) {root = insert(X,root);}
    Node* insert(Value X,Node*T)
    {
        if ( T == nil ) {
        T = new Node( X );
        } else if ( X < T->value ) {
        T->left = insert( X, T->left );
        } else if ( X > T->value ) {
        T->right = insert( X, T->right );
        } else {
        T->value = X;
        }
        return T;
        
    }
    void remove( Value X ) { root = remove( X, root ); }
    Node* remove( Value X, Node*& T )
    {
    
    if ( T != nil ) {
    if ( X > T->value ) {
    T->right = remove( X, T->right );
    } else if ( X < T->value ) {
    T->left = remove( X, T->left );
    } else {
    if ( T->right != nil ) {
    Node* x = T->right;
    while ( x->left != nil ) x = x->left;
    T->value = x->value; 
    T->right = remove( T->value, T->right );
    } else if ( T->left != nil ) {
    Node* x = T->left;
    while ( x->right != nil ) x = x->right;
    T->value = x->value;
    T->left = remove( T->value, T->left );
    } else {
    delete T;
    T = nil;
    }
    }
    }
   
    return T;
    }
    
    void okay( ) { okay( root ); }
    void okay( Node* T ) {
  
    return;
    }




};


#endif