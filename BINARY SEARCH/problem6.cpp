#include <iostream>
using namespace std;
// Find Minimum In Rotated Sorted Array[Unique]
// Time Complixity -> O(log N)
int findminimum(int arr[], int n)
{
    int low = 0, high = n - 1;
    int ans = INT32_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    cout << findminimum(arr, 7);
    return 0;
}