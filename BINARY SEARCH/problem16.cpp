#include <iostream>
#include <vector>
using namespace std;
// kth Missing Positive Number
int KthMissingNumber(vector<int> &Arr, int K)
{
    int low = 0, high = Arr.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = Arr[mid] - (mid + 1);
        if (missing < K)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return K + high + 1;
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 10};
    cout << KthMissingNumber(arr, 5);
    return 0;
}