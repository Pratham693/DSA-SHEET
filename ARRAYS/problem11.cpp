#include <iostream>
using namespace std;
// Linear Search Nth Occurence
int linear_search(int arr[], int n, int key, int k)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            j++;
        }

        if (j == k)
        {
            return i;
            break;
        }
        
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 4, 8, 9, 10};
    cout << linear_search(arr, 10, 4, 2);

    return 0;
}