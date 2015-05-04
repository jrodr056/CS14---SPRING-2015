#include "lab4.h"
#include <sstream>
int main( int argc, char*argv[])
{
    istringstream ss(argv[1]);
    int x;
    if (!(ss >> x))
    exit(0);
    inorder(x);
    
    
}