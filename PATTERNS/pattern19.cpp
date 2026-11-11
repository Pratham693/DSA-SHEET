#include <iostream>
using namespace std;
void pattern(int n)
{
    int space = 0;

    for (int i = 1; i <= n; i++)
    {
        // For Stars
        for (int j = 1; j <= n - i+1; j++)
        {
            cout << "*";
        }
        // FOr Spaces
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        // For Stars

        for (int j = 1; j <= n - i+1; j++)
        {
            cout << "*";
        }
        space = space+2;
        cout<<endl;
    }

     space = 2 * n - 2;

    for (int i = 1; i <= n; i++)
    {
        // For Stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // FOr Spaces
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        // For Stars

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        space = space-2;
        cout<<endl;
    }
}

int main()
{
pattern(5);
    return 0;
}