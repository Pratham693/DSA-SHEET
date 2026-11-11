#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void union1(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int s1 = a.size();
    int s2 = b.size();

    int i = 0, j = 0;
    vector<int> unionarr;

    while (i < s1 && j < s2)
    {
        if (a[i] <= b[j])
        {
            if (unionarr.empty() || unionarr.back() != a[i])
                unionarr.push_back(a[i]);
            i++;
        }
        else
        {
            if (unionarr.empty() || unionarr.back() != b[j])
                unionarr.push_back(b[j]);
            j++;
        }
    }

    while (i < s1)
    {
        if (unionarr.empty() || unionarr.back() != a[i])
            unionarr.push_back(a[i]);
        i++;
    }

    while (j < s2)
    {
        if (unionarr.empty() || unionarr.back() != b[j])
            unionarr.push_back(b[j]);
        j++;
    }

    for (int x : unionarr)
        cout << x << " ";
}

int main()
{
    vector<int> n1 = {1, 2, 6, 3, 4, 54};
    vector<int> n2 = {1, 3, 4, 2, 6, 9};

    union1(n1, n2);

    return 0;
}