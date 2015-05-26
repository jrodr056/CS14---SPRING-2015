//Jose Rodriguez
//861090575
//05/25/15

//Approach: randomize vector of strings 
//output times on another txt

//part A

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
#include <chrono>
#include <unordered_set>
#include <time.h>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void random(vector<string>& v)
{
    for(unsigned j = 0; j<v.size(); j++)
    {
        swap(v[rand()%v.size()],v[rand()%v.size()]);
    }
    
}


int main( int argc, char* argv[] )
{
    vector<string> mylist;
    
    ifstream inFS;
    ofstream out;
    out.open("data.txt");
    string dog = argv[1];
    
    inFS.open(dog.c_str());
    string word;
    
    if(!inFS.is_open())
    {
        cout<<"file failed to open."<<endl;
        exit(-1);
    }
    else
    {
       while(inFS>>word)
       {
           mylist.push_back(word);           
           
       }
         
        inFS.close();
    }       
 
    bool endrun;
    set<string> tree;
    unordered_set<string> hashTable;
    chrono:: duration<double> time_span;

    int n = 0;
    while(n<50000 && !endrun)
    {
        out<<n<< " ";
        
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        for(int i =0; i<n; i++)
        {
            tree.insert(mylist.at(i));
        }
         high_resolution_clock::time_point t2 = high_resolution_clock::now();
         
         time_span = duration_cast<duration<double>>(t2-t1);
         
         out<<time_span.count() << " ";
         
         
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        for(int i =0; i<n; i++)
        {
            hashTable.insert(mylist.at(i));
        }
         high_resolution_clock::time_point t4 = high_resolution_clock::now();
         
         time_span = duration_cast<duration<double>>(t3-t4);
         
         out<<time_span.count() << " ";
         
         
          high_resolution_clock::time_point t5 = high_resolution_clock::now();
          for(int i =0; i<n; i++)
          {
            tree.find(mylist.at(i));
          }
         high_resolution_clock::time_point t6 = high_resolution_clock::now();
         
         time_span = duration_cast<duration<double>>(t5-t6);
         
         out<<time_span.count() << " ";
         
         
          high_resolution_clock::time_point t7 = high_resolution_clock::now();
          for(int i =0; i<n; i++)
          {
            hashTable.find(mylist.at(i));
          }
         high_resolution_clock::time_point t8 = high_resolution_clock::now();
         
         time_span = duration_cast<duration<double>>(t7-t8);
         
         out<<time_span.count() << " ";
         
         if(n<=50000)
         n+=5000;
         if(n>50000)
         endrun = true;
         
         random(mylist);
         out<<endl;
    }
    return 0;
}
