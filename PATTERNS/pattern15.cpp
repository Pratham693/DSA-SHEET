#include <iostream>
using namespace std;
void pattern(int n){
    char ch = 'A';
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j<=i; j++)
        {
            cout<<ch<<"";
        }
        cout<<endl;
        ch = ch+1;
    }
    
}

int main()
{
    pattern(5);
    return 0;
}