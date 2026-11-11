#include <iostream>
using namespace std;
// Find Peak Element In The Array
// Time Complixity O(log N)
int findpeak(int arr[], int n)
{
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            low = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            high = mid - 1;
        }
        else
        {
            // For Multiple Peaks
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 4};
    cout << findpeak(arr, 10);
    return 0;
}