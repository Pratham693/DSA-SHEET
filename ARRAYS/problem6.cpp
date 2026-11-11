#include <iostream>
using namespace std;
// Q - Left  Rotate The Array By 1 place.
// Brute Force
//  Time Complexity =  O(n);
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
}
void rotate(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    cout << endl;
}
// Optimized Version
void rotate2(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    cout<<endl;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Before Rotation" << endl;
    print(arr, 5);
    rotate(arr, 5);
    cout << "After Rotation" << endl;
    print(arr, 5);
    rotate2(arr, 5);

    print(arr, 5);
    return 0;
}