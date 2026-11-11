#include <iostream>
using namespace std;
// Find Out How Many Time A Array Has Been Roated
//  Time Complixity -> O(log n);
int findrotation(int arr[], int n)
{
    int low = 0, high = n - 1;
    int ans = INT32_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            high = mid + 1;
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
        }
    }
    return index;
}
int main()
{
    int arr[] = {3, 4, 5, 1, 2};
    cout << findrotation(arr, 5);
    return 0;
}