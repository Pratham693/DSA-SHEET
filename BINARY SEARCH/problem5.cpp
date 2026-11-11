#include <iostream>
using namespace std;
// Search Element In Sorted Array With Duplicate
bool SearchInRoatedAortedArr(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;
    bool flag = SearchInRoatedAortedArr(arr, 10, 3);
    if (flag == true)
    {
        cout << "Target Founded";
    }
    else
    {
        cout << "Target not found";
    }

    return 0;
}