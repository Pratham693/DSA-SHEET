#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> st;
    //inserting In Set
    st.insert(20);
    st.insert(10);
    st.insert(30);
    st.insert(10);
    //stores The data In A Sorted Manner And It Does Not Stores Duplicate
    //other Function Works Same AS Vector
    auto it = st.find(10); // points to The Second Element
    st.erase(st.begin(), st.end()); //erase the Entire Element From The Set

    return 0;
}