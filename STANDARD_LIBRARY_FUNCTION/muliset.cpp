#include <iostream>
#include<set>
using namespace std;

int main()
{
    // Same As Set But It Stores Duplicate Element
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);
    
    ms.erase(10); // delets The All 10 Values From The Set
    ms.erase(ms.find(10)); // delete only 10 from the set
    // ms.erase(ms.find(1), ms.find(1) + 2);

    return 0;
}