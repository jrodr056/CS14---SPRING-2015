#include "selectionsort.h"


int main()
{
    list<int> m1;
    m1.push_back(2);
    m1.push_back(4);
    m1.push_back(4); //will not swap with the other 4 because it is = not <
    m1.push_back(5);
    m1.push_back(1);
    m1.push_back(8);
    m1.push_back(9);
    selectionsort(m1);
}