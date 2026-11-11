#include <iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.emplace_back(2);
    l.push_front(1);
    l.emplace_front(6);
    // Rest Function Same As Vector
    list<int> :: iterator it = l.begin();
    //Clearing The List
    l.clear();
    //Inserting At Some Specific Position
    l.insert(l.begin(), 5);
    
    return 0;
}