#include <iostream>
using namespace std;
void print_number(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    i++;
    print_number(i, n);
}

int main()
{
    int n;
    cin >> n;
    print_number(1, n);
    return 0;
}