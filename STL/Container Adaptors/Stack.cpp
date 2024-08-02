#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("First");
    s.push("Middle");
    s.push("Last");

    cout<<"Top Element : "<<s.top()<<"\n";
    s.pop();
    cout<<"Top Element : "<<s.top()<<"\n";
    cout<<"Size of Stack "<<s.size()<<"\n";
    cout<<"Empty or not "<<s.empty()<<"\n";
}