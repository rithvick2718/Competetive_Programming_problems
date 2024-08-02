#include<iostream>
#include<set>
using namespace std;
void printset(const set<int> &S)
{
    for(auto s: S)
    {
        cout<<s<<" ";
    }
    cout<<"\n";
}
int main()
{
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0); //insertion is O(log n)
    printset(s);
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    printset(s);
    cout<<"Is 5 there : "<<s.count(5)<<"\n";
    cout<<"Is -5 there : "<<s.count(-5)<<"\n";
    set<int>::iterator itr = s.find(5);
    cout<<"The value at itr "<<*itr<<"\n";
    for(set<int>::iterator p =itr; p!=s.end();p++) //another way to print
    {
        cout<<*p<<" ";
    }
    cout<<"\n";
}