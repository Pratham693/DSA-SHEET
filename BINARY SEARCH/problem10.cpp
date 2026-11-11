#include <iostream>
using namespace std;
// Find The Square Root Of An Integer
int findSquareRoot(int arr[], int n, int target)
{
    int low = 1, high = n;
    int ans = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid <= target)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findSquareRoot(arr, 10, 28);

    return 0;
}