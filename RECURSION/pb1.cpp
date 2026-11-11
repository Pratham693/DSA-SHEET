#include <iostream>
// Parameterized
// Sum Of N number Using Recursion BackTracking
using namespace std;
void Sum(int n, int sum)
{
    if (n < 1)
    {
        cout << "Sum = " << sum << endl;
        return;
    }
    Sum(n - 1, sum + n);
}

int main()
{
    int n;
    cin >> n;
    Sum(n, 0);
    return 0;
}