#include <iostream>
using namespace std;
// Time Complexity = O(n)
// Q - Remove Duplicates from THe array

int main()
{
    int arr[10] = {1, 1, 2, 2, 3, 4, 5, 5, 9, 10};
    int i = 0;
    for (int j = 1; j < 10; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    cout << "Total Unique Element = " << i + 1 << endl;
    for (int j = 0; j < i + 1; j++)
    {
        cout << arr[j] << ", ";
    }

    return 0;
}