#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    unsigned int x;
    while (t--)
    {
        cin>>x;
        while(x!=0)
        {
            a.push_back(x%2);
            x=x/2;
        }
        cout<<a.size()<<"\n";
        for(auto k : a)
        {
            cout<<k<<" ";
        }
        cout<<"\n";
        a.clear();
    }
}