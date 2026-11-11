#include <bits/stdc++.h>
using namespace std;
// Select The Minimum And Swap It
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min_idx = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before Sorting" << endl;
    print(arr, n);
    cout << "Array After Sorting" << endl;
    selection_sort(arr, n);
    print(arr, n);
    return 0;
}
// TIme Complexity = O(n^2);