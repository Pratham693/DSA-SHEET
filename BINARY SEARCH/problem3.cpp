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
    int n = 10;
    int target;
    cin >> target;
    int arr[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int lb = firstoccurence(arr, n, target);
    if (lb == n || arr[lb] != target)
    {
        cout << " -1, -1" << endl;
    }
    else
    {
        int ub = lastoccurence(arr, 10, target) - 1;
        int count = ub - lb + 1;
        cout << count; // Number of occurence
    }

    return 0;
}