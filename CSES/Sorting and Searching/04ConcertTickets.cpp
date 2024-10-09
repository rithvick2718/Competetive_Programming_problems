#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int t;
    multiset<int>h;
    for(int i=0; i<n; i++)
    {
        cin>>t;
        h.insert(t);
    }
    for(int i=0; i<m; i++)
    {
        cin>>t;
        if(h.size()!=0){
            auto it = h.upper_bound(t);
            if(it!=h.begin())
            {
                --it;
                cout<<*it<<"\n";
                h.erase(it);
            }
            else cout<<-1<<"\n";
        }
        else cout<<-1<<"\n";
    }
}