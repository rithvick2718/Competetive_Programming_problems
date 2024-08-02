#include<iostream>
#include<deque>
using namespace std;
void printdeque(const deque<int> &d)
{
    for(int i : d)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    return;
}
int main()
{
    deque<int> d;
    d.push_front(2);
    d.push_back(1);
    printdeque(d);
    d.pop_front();
    printdeque(d);
    d.push_front(2);
    d.pop_back();
    printdeque(d);
    d.push_back(1);
    cout<<"Element at index 1 (0-index) "<<d.at(1)<<"\n";
    cout<<"Element at index 1 (0-index) "<<d[1]<<"\n";
    cout<<"Front "<<d.front()<<"\n";
    cout<<"Back "<<d.back()<<"\n";
    cout<<"Empty or not "<<d.empty()<<"\n";
    cout<<"Before erasing the size "<<d.size()<<"\n";
    d.erase(d.begin(), d.begin()+1);
    cout<<"After erasing the size "<<d.size()<<"\n";
    return;
}