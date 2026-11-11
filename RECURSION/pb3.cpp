#include <iostream>
// Functional Recursion
using namespace std;
// Factorial Of N Number 
int Facto(int n)
{

    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * Facto(n - 1);
}


int main()
{
 int n;
 cin>>n;
 cout<<Facto(n);
 
    return 0;
}