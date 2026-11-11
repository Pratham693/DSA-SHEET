#include <iostream>
using namespace std;
// Second Largest Element in array
// Time Complexity = O(2n)
int main()
{
    int arr[5] = {20, 30, 22, 13, 45};
    int first_largest = arr[0];

    for (int i = 0; i < 5; i++)
    {
        if (first_largest <arr[i])
        {
            first_largest = arr[i];
        }
    }
    int second_largest = -1;
    for (int i = 0; i <5; i++)
    {
        if (second_largest < arr[i] && arr[i] != first_largest )
        {
            second_largest = arr[i];
        }
        
    }
    cout<<second_largest;
    return 0;
}