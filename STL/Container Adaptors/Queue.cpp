#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<string> q;
    q.push("First");
    q.push("Middle");
    q.push("Last");
    cout<<"First Element "<<q.front()<<"\n";
    q.pop();
    cout<<"First Element "<<q.front()<<"\n";
    cout<<"Size after q.pop() "<<q.size()<<"\n";
}