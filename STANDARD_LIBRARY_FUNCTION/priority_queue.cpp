#include <iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq; // Max Heap
    pq.push(5);
pq.push(2);
pq.push(8);
pq.push(10);
cout<<pq.top()<<endl; //prints 10
pq.pop(); //will Remove The Top Element 10
// Other Function Works Same As Vector
//Min Heap
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(20); //{20}
pq.push(10); //{10, 20}
pq.push(30); //{10, 20, 30}
pq.push(40); //{10, 20, 30, 40}
cout<<pq.top()<<endl; //prints 10
    return 0;
}