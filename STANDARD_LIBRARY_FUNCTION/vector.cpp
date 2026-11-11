#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    // Normal Vector
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.emplace_back(5);
    // Iterator
    // traversing on the vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    // or
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    // Vector Of Pair
    vector<pair<int, int>> v1;
    v1.push_back({1, 3});
    v1.push_back({3, 4});
    // Diffrent Type Of Initialization In Vector
    vector<int> v{5, 100}; //{100, 100, 100, 100, 100}
    vector<int> v{5};      //{0, 0, 0, 0, 0};
    vector<int> v2{5, 20}; // {20, 20, 20, 20, 20};
    // copying value of another Vector to that vector;
    vector<int> v3{v2}; //{20, 20, 20, 20, 20};
                        //  Diffrent Type Of Function
    vector<int>::iterator it1 = v.begin();
    vector<int>::iterator it2 = v.end();
    //  vector<int> :: iterator it3 = v.rend();it point right to the end of the vector
    //  vector<int> :: iterator it4 = v.rbegin(); it point to the right to the begining of the vector
    // Printing Vector element;

    cout << v[0] << " " << v.at(0) << endl;
    cout << v.back() << endl;
    // Erasing Element Values In The Vector
    v.erase(v.begin()+1) ;// Deletes THe Specific Element
    v.erase(v.begin() +1 , v.end()); // Deletes the Element Which Comes In The Range 
    // Disclimer :- End Point Pass THat index Which Is JUst Riht TO The Range of deletes Element
    // Inserting Element In The Vector(Insert Function)
    vector<int> v4{2, 100}; // {100, 100}
    v4.insert(v4.begin(), 300); //{300, 100, 100}
    v4.insert(v4.begin() + 1 , 2, 20); // {300, 20, 20, 100, 100}
    vector<int> copy{2, 50};
    v4.insert(v.begin(), copy.begin(), copy.end()); // inserting range of elemnet From Another Vector
    cout<<v4.size(); // gives the size of the Vector
    v.pop_back() ;// Pops The Element From Back
    vector<int> v5;
    v5.push_back(2);
    v5.push_back(4); //{2, 4}
    vector<int> v6;
    v6.push_back(1);
    v6.push_back(6); //{1,6}
    v5.swap(v6); //v5 = {1, 6} and v6 = {2, 4}
    //erasring The Element
    // v1.erase it erase The Entire Element From The Vector
 

    return 0;
}