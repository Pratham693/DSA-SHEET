#include <iostream>
#include <vector>
using namespace std;

int missing(vector<int> &a, int N)
{
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++)
    {
        xor2 ^= a[i];      // XOR of array elements
        xor1 ^= (i + 1);   
    }

    xor1 ^= N;  

    return xor1 ^ xor2;
}

int main()
{
    vector<int> a = {1, 2, 3, 5, 6, 7, 8, 9, 10};

    cout << missing(a, 10);

    return 0;
}