#include <iostream>
using namespace std;
void pattern(int n){
    for (int i = 0; i <= n; i++)
    {
        for (char ch = 'A'; ch <= (n-i-1 )+'A'; ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
        
    }
    
}


int main()
{
    pattern(5);
    
    return 0;
}