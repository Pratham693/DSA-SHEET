#include <iostream>
using namespace std;
void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i <= n; i++)
    {
        cout<<"* ";
    }
    cout<<endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    pattern9(5);
    return 0;
}