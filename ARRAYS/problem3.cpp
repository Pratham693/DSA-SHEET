#include <iostream>
#include <vector>
using namespace std;
void largest(int arr[], int n)
{
    int largest = arr[0];
    int second_largest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest)
            second_largest = arr[i];
    }
    cout << "Largest = " << largest << endl;
    cout << "Second_largest = " << second_largest << endl;
}

int main()
{
    int arr[5] = {1, 30, 300, 22, 14};
    largest(arr, 5);
    return 0;
}