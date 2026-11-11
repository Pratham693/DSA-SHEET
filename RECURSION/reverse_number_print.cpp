#include <iostream>
using namespace std;
void Print_reverse(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << n << endl;
    n--;
    Print_reverse(i, n);
}

int main()
{
    int n;
    cin >> n;
    Print_reverse(1, n);
    return 0;
}