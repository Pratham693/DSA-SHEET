#include <iostream>
using namespace std;
int binary_search(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            cout << "target founded " << arr[mid] << endl;
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 15, 18, 39, 90, 140, 333, 777};
    cout << binary_search(arr, 10, 777);
    return 0;
}