#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int m;
    while(t--)
    {
        cin>>m;
        int n;
        int take;
        map<int, int> MAP;
        for(int i=0; i<m;i++)
        {
            cin>>n;
            while(n--)
            {
                cin>>take;
                MAP[take]=i;
            }
        }
        vector<set<int>> SETS(m);
        for(auto x : MAP)
        {
            SETS[x.second].insert(x.first);
        }
        bool can = true;
        for(int i=0; i<m; i++)
        {
            if(SETS[i].size()==0)
            {
                can = false;
                break;
            }
        }
        if(can)
        {
            for(int i=0; i<m; i++)
            {
                cout<<*SETS[i].begin()<<" ";
            }
        }
        else cout<<-1;
        cout<<"\n";
    }
}