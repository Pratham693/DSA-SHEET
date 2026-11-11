#include <iostream>
using namespace std;
void backTracking_printing(int i, int n)
{
    if (i<1)
    {
        return;
    }
    backTracking_printing(i - 1, n);
    cout << i<<endl;
}
int main()
{

    int n;
    cin >> n;
    backTracking_printing(n, n);
    return 0;
}