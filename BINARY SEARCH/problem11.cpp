#include <iostream>
using namespace std;
// Find The Nth Root Of Given Integer N
// Multiplication Function
int multiplynum(int num, int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * num;
    }

    return ans;
}
int findtheNthRoot(int n, int M)
{

    int low = n, high = M;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int ans = multiplynum(mid, n);
        if (ans == M)
        {
            return mid;
        }
        else if (ans < M)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
int main()
{
    cout<<findtheNthRoot(4, 256);
    return 0;
}