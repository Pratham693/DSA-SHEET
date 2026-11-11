#include <iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> st;
    //Inserting In Stack
    st.push(20);
    st.push(30);
    st.push(2);
    st.push(37);
    st.push(10);
// Deleting in Stack
st.pop(); // the TOp Most Element Will Poped
cout<<st.top()<<endl; // It Prints The Element Which IS ON Top
// Finding The Stack Size means HOw Many Elemnet Are Currently Stored In The Stack;
 int n = st.size();
 //Checking That Stack Is Empty Or Full
 st.empty();
 //Swapping Two Stacks;
 stack<int> st1, st2;
 st1.swap(st2); // This Function will Swap This Stack
    return 0;
}