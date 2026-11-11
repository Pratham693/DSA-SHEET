#include <iostream>
#include<deque>
using namespace std;

int main()
{
    // Double Ended Queue Insertion Is possible From both The End;
    deque<int> dq;
    //inserting In Dq
    dq.push_back(2);
    dq.push_back(3);
    dq.emplace_back(2);
    dq.push_front(1);
    dq.emplace_front(6);
    //Acssecing The Element
    dq.front();
    dq.back();
    //Rest Function Are Same As Vector
    return 0;
}