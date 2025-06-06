#include<bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
#define ll long long 
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> x(n);
    vector<ll> dp(m+2,0); //dp[0] = 0. and dp[m+1]=0.
    cin>>x[0];
    if(x[0]==0)
        for(ll i=1; i<=m; i++) 
            dp[i]=1;
    else{
        dp[x[0]]=1;
    }
    vector<ll> ndp(m+2,0);
    ll ans=1;
    for(ll i=1; i<n; i++){
        cin>>x[i];
        if(x[i]==0){
            for(ll i=1; i<=m; i++){
                ndp[i]=(dp[i-1]+dp[i]+dp[i+1])%MOD;
            }
            dp=ndp;
            ndp.assign(m+2,0);
        }
        else{
            ans=(ans*(dp[x[i]-1]+dp[x[i]]+dp[x[i]+1]))%MOD;
            dp.assign(m+2,0);
            dp[x[i]]=1;
        }
    }
    if(x[n-1]==0){
        ll sum=0;
        for(ll i=1; i<=m; i++){
            sum=(sum+dp[i])%MOD;
        }
        ans=(ans*sum)%MOD;
    }
    cout<<ans;
}