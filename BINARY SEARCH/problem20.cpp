#include <bits/stdc++.h>
using namespace std;

// Minimum Maximum Distance Between Gas Stations

int countStations(vector<int>& arr, double dist)
{
    int cnt = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int gap = arr[i] - arr[i - 1];
        int stations = ceil(gap / dist) - 1;
        cnt += stations;
    }

    return cnt;
}

double minimiseMaxDistance(vector<int>& arr, int k)
{
    double low = 0;
    double high = arr.back() - arr.front();

    for (int i = 0; i < 100; i++)
    {
        double mid = (low + high) / 2;

        if (countStations(arr, mid) > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int k = 2;

    cout << fixed << setprecision(6);
    cout << minimiseMaxDistance(arr, k);

    return 0;
}