#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Q - Left  Rotate The Array By  D place.

//  Time Complexity =  O(n);
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
}

void rotate2(int arr[], int n, int k)
{
    if (k > n)
    {
        k = k % n;
    }
    while (k--)
    {
        int temp = arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = temp;
    }

    cout << endl;
}
void reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int arr[], int n, int k)
{
    reverse(arr, 0, k - 1);
    reverse(arr, k, n-1);
    reverse(arr, 0, n-1);
    cout<<endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Before Rotation" << endl;
    print(arr, 5);
    // rotate2(arr, 5, 5);
    rotate(arr, 5, 3);
    cout << "After Rotation" << endl;
    print(arr, 5);

    return 0;
}