#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int KthElement(vector<int> &A, vector<int> &B, int k)
{
    if (A.size() > B.size())
        return KthElement(B, A, k);

    int n1 = A.size();
    int n2 = B.size();

    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;

        int leftA, rightA, leftB, rightB;

        if (mid1 == 0)
            leftA = INT_MIN;
        else
            leftA = A[mid1 - 1];

        if (mid1 == n1)
            rightA = INT_MAX;
        else
            rightA = A[mid1];

        if (mid2 == 0)
            leftB = INT_MIN;
        else
            leftB = B[mid2 - 1];

        if (mid2 == n2)
            rightB = INT_MAX;
        else
            rightB = B[mid2];

        if (leftA <= rightB && leftB <= rightA)
        {
            return max(leftA, leftB);
        }
        else if (leftA > rightB)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {1, 3, 8};
    vector<int> B = {2, 7, 10, 12, 15};

    int k = 5;

    cout << KthElement(A, B, k);

    return 0;
}