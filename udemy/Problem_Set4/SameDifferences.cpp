#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        unordered_map<int,long long> mp;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            mp[a-i]++;
        }
        long long ans=0;
        for(auto x :mp)
        {
            ans+=((x.second)*(x.second-1))/2;
        }
        cout<<ans<<"\n";
    }
}