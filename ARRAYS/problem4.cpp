#include <iostream>
using namespace std;
// Check if array Is Sorted Or Not
//  Time Complexity = O(n)
void bubble_sort(int arr[], int n)
{
    int swapdid = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapdid = 1;
            }
        }
        if (swapdid == 1)
        {
            break;
        }
    }
    if (swapdid == 0)
    {
        cout << "The Array Is sorted\n";
    }
    else
    {
        cout << "The Array Is Unsorted\n";
    }
}
int main()
{
 int arr[5] = {1, 20, 30, 22, 30};
 int arr2[5] = {1, 2, 3, 4, 5};
 bubble_sort(arr, 5);
 bubble_sort(arr2, 5);
    return 0;
}