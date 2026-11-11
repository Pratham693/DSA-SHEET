#include <iostream>
using namespace std;
int binary_search(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            cout << "target founded " << arr[mid] << endl;

            return mid;
        }
        else if (arr[mid] > target)
        {
            // Shrinking To the Left Side Of The array
            return binary_search(arr, low, mid - 1, target);
        }
        else
        {
            // Shrinking To the Right Side Of The array

            return binary_search(arr, mid + 1, high, target);
        }
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 15, 18, 39, 90, 140, 333, 777};
    cout << binary_search(arr, 0, 10, 15);
    return 0;
}