#include <iostream>
using namespace std;
// First And Last Occurrence of X
int firstoccurence(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int lastoccurence(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int lb = firstoccurence(arr, 10, 4);
    if (lb == 10 || arr[lb] != 4)
    {
        cout << " -1, -1" << endl;
    }
    else
    {
        cout << lb << ", " << lastoccurence(arr, 10, 4) - 1;
    }

    return 0;
}