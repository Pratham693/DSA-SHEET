#include <iostream>
#include<queue>
using namespace std;

int main()
{
    //Queue Insertion Is Possible Only From The Rear
    // Works On FIFO
    queue<int> q;
    //inserting In the Queue
    q.push(2); // {2}
    q.push(3); // {2, 3}
    q.emplace(2); //{2, 3, 2}
    // Adding Any Number In The Queue
    q.back() += 5; //{2, 3, 7}
    cout<<q.back()<<endl;  // Prints 8
    cout<<q.front()<<endl; // Prints 2
    q.pop() ;// remove 2 from the Queue
    cout<<q.front()<<endl; //Prints 3

    return 0;
}