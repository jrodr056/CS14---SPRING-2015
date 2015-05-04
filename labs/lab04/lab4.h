//Jose Rodriguez
//861090575
//03/27/15

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void preorderRecurse(int m, int n, int k)
{
        cout<<m<<","<<n<<endl;
        if(2*m-n+m<k)
        preorderRecurse(2*m-n,m,k);
        if(2*m+n+m<k)
        preorderRecurse(2*m+n,m,k);
        if(2*n+m+n<k)
        preorderRecurse(2*n+m,n,k);
    
}

void postorderRecurse(int m, int n, int k)
{
        if(2*m-n+m<k)
        postorderRecurse(2*m-n,m,k);
        if(2*m+n+m<k)
        postorderRecurse(2*m+n,m,k);
        if(2*n+m+n<k)
        postorderRecurse(2*n+m,n,k);
        cout<<m<<","<<n<<endl;
}

typedef pair<int,int> Entry;
void inorderRecurse(int m, int n, int k, priority_queue<Entry> &mypq)
{
     if(2*m-n+m<k)
     inorderRecurse(2*m-n,m,k,mypq);
     if(2*m+n+m<k)
     inorderRecurse(2*m+n,m,k,mypq);
     mypq.push(Entry(m,n));
     if(2*n+m+n<k)
     inorderRecurse(2*n+m,n,k,mypq);
    
}

void preorder(int k)
{
    cout<<"preorder "<<endl;
    preorderRecurse(2,1,k);
    preorderRecurse(3,1,k);
    
}

void postorder(int k)
{
    cout<<"postorder "<<endl;
    postorderRecurse(2,1,k);
    postorderRecurse(3,1,k);
    
}
typedef pair<int,int> Entry;
void inorder(int k)
{
    priority_queue <Entry>mypq;
    stack <Entry>myPrint;
    cout<<"inorder "<<endl;
    inorderRecurse(2,1,k,mypq);
    inorderRecurse(3,1,k,mypq);
    
    while(mypq.empty()==false)
    {
        myPrint.push(mypq.top());
        mypq.pop();
    }
    
    while(myPrint.empty()==false)
    {
        cout<<myPrint.top().first<<","<<myPrint.top().second<<endl;
        myPrint.pop();
    }
}


    
    
    