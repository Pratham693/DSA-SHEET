#include <iostream>
#include <queue>
using namespace std;
//  Moving Zero To The End ;
void zero_end(int arr[], int n)
{
    queue<int> l;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int a = arr[i];
            l.push(a);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!l.empty())
        {
            arr[i] = l.front();
            l.pop();
        }
        else
        {
            arr[i] = 0;
        }
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
    int arr[10] = {1, 2, 0, 0, 3, 4, 0, 5, 6, 8};
    print(arr, 10);
    zero_end(arr, 10);
    print(arr, 10);
    return 0;
}