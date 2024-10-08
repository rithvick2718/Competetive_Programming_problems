#include<iostream>
#include<set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    cin>>n;
    set<int> s;
    while(n--)
    {
        cin>>a;
        s.insert(a);
    }
    cout<<s.size();
}