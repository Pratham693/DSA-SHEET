#include <iostream>

using namespace std;

int main()
{
    // Normal Pair;
    pair<int, int> p1 = {1, 2};
    // Acsessing Normal Pair
    cout << p1.first << " " << p1.second << endl;

    // Nested Pair:- Pair Inside Pair.
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    // Acsessing Nested Pair
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
    // Array of Pair
    pair<int, int> p3[] = {{1, 2}, {2, 3}, {2, 4}};
    // Traversing On Pair
    for (int i = 0; i < 3; i++)
    {
        cout<<p3[i].first<<" "<<p3[i].second<<endl;
    }
    

    
    return 0;
}