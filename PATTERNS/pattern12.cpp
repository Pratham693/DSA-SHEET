#include <iostream>
using namespace std;
void Pattern(int n){
    int count = 1;
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0;  j < i; j++)
        {
            cout<<count<<" ";
            count = count+1;
        }
        cout<<endl;
        
    }
    
}

int main()
{
    Pattern(5);
    return 0;
}