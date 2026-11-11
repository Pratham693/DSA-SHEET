#include <iostream>
using namespace std;
void backTracking_printing(int i, int n)
{
    if (i<1)
    {
        return;
    }
    cout << i<<endl;
    backTracking_printing(i - 1, n);
    
}
int main()
{

    int n;
    cin >> n;
    backTracking_printing(n, n);
    return 0;
}