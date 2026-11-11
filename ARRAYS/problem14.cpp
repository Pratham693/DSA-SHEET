#include <iostream>
#include <vector>
using namespace std;
// Intersection of two sorted array.
void intersection1(vector<int> v1, vector<int> v2)
{
    int s1 = v1.size();
    int s2 = v2.size();
    int j = 0;
    int i = 0;
    vector<int> intersectarr;
    while (i < s1 && j < s2)
    {
        if (v1[i] < v2[j])
        {
            i++;
        }
        else if (v1[i] > v2[j])
        {
            j++;
        }
        else
        {
            intersectarr.push_back(v1[i]);
            i++;
            j++;
        }
    }
    for (int x : intersectarr)
    {
        cout << x << ", ";
    }
    cout << endl;
}
int main()
{
    vector<int> n1 = {1, 2, 3, 4, 5, 6, 6, 7};
    vector<int> n2 = {1, 2, 2, 3, 4, 5, 6};
    intersection1(n1, n2);

    return 0;
}