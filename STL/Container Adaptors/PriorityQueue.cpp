#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //max heap
    priority_queue<int> maxi;
    //min heap
    priority_queue<int, vector<int> , greater<int>> mini; //why?
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    cout<<"Size of maxi "<<maxi.size()<<"\n";
    int size =maxi.size();
    for(int i=0; i<size;i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<"\n";

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    size=mini.size();
    for(int i=0; i<size;i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<"\n";
    cout<<"Is mini empty "<<mini.empty();
    return 0;
}