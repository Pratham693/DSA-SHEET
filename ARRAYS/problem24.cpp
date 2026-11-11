#include <iostream>
#include <vector>
using namespace std;
// If Positive And Negative Numbers are Not Equal
void arrange(vector<int> &arr)
{
    vector<int> posi;
    vector<int> negi;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            posi.push_back(arr[i]);
        }
        else
        {
            negi.push_back(arr[i]);
        }
    }

    if (posi.size() > negi.size())
    {
        for (int i = 0; i < negi.size(); i++)
        {
            arr[2 * i] = posi[i];
            arr[2 * i + 1] = negi[i];
        }
        int index = negi.size() * 2;
        for (int i = negi.size(); i < posi.size(); i++)
        {
            arr[index] = posi[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < posi.size(); i++)
        {
            arr[2 * i] = posi[i];
            arr[2 * i + 1] = negi[i];
        }
        int index = posi.size() * 2;
        for (int i = posi.size(); i < negi.size(); i++)
        {
            arr[index] = negi[i];
            index++;
        }
    }
}

int main()
{
    vector<int> arr = {1, -2, 3, 4, -2, -4, -4};
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<", ";
    }
    cout << endl;
    arrange(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<", ";
    }

    return 0;
}