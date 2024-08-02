#include<iostream>
#include<list>
using namespace std;
void printlist(const list<int> &l)
{
    for(int i : l)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    return;
}
int main()
{
    //this is a doubly linked list
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    printlist(l);
    //pop_back and pop_front also work too
    l.erase(l.begin());
    cout<<"After erase \n";
    cout<<"Size of list "<<l.size()<<"\n";
    //can also initialize it like this:
    list<int> n(l);
    list<int> m(5,2); //the same way as vectors
    printlist(m);
}