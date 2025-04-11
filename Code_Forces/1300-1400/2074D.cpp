#include<bits/stdc++.h>
using namespace std;
// wow so 1,000,000,007 i.e. 1e9 +7 is prime
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while (tt--)
    {
        int n,m;
        cin>>n>>m;
        vector<ll> x(n), r(n);
        for(int i=0; i<n; i++) cin>>x[i];
        for(int i=0; i<n; i++) cin>>r[i];
        unordered_map<ll,ll> mp;
        ll pts;
        for(int i=0; i<n; i++)
        {
            for(ll j =-r[i]; j<=r[i]; j++)
            {
                pts=sqrt(r[i]*r[i]-j*j);
                pts=1+(int)2*pts;
                mp[x[i]+j]=max(mp[x[i]+j],pts);
            }
        }
        ll ans=0;
        for(auto p : mp){
            ans+=p.second;
        }
        cout<<ans<<"\n";
    }
}