#include <iostream>
#include<map>
using namespace std;

int main()
{
    //map{key, value}
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    map<pair<int, int>, int> mpp2;
    //Insertion In The Map
    mpp[1] = 2; // insertion for first map
    mpp1[1] = {1, 2}; // insertion for second map
    mpp2[{1, 3}] = 20; // insertion for third map
// map stores key in sorted Manner
// for (auto it: mpp1)
// {
//     cout<<it.first<<" "<<it.second<<endl;
// }
// this loop Will Traverse All The Map And Prints The Values


    return 0;
}