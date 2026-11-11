#include <iostream>
using namespace std;
void Pattern5(int n){
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <= n-i-1; j++)
        {
            cout<<i+1<<" ";
        }
      cout<<endl;   
    }
    
}

int main()
{
    Pattern5(5);
    return 0;
}