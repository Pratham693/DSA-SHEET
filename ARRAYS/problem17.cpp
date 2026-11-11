#include <iostream>
#include <vector>
using namespace std;

int max1(vector<int> &a)
{
    int mx = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > mx)
            mx = a[i];
    }
    return mx;
}

int maximum_consecutive(int arr[], int n)
{
    vector<int> v;
    int consecutive = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            consecutive++;
        }
        else
        {
            v.push_back(consecutive);
            consecutive = 0;
        }
    }

    v.push_back(consecutive); // store last count

    return max1(v);
}

int main()
{
    int arr[10] = {0, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    cout << maximum_consecutive(arr, 10) << endl;

    return 0;
}