#include <iostream>
using namespace std;
// Q1- Largest Element In The Array
//  Time Complexity = O(n);
int main()
{
    int arr[5] = {1, 30, 49, 12, 30};
    int max = arr[0];

    for (int i = 0; i < 5; i++)
    {
        if (max <arr[i])
        {
            max = arr[i];
        }
    }
    cout << max;
    return 0;
}