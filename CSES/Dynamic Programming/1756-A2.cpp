#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1'000'000'007LL
int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll> dp(m+2,0LL);
    vector<ll> ndp(m+2,0LL);
    int x;
    cin>>x;
    if(x==0)
        for(int i=1; i<=m; i++) dp[i]=1LL;
    else
        dp[x]=1LL;
    ll ans=1LL;
    ll wv; //work variable
    for(int i=1; i<n; i++){
        cin>>x;
        if(x==0){
            for(int i=1; i<=m; i++)
                ndp[i]=(dp[i-1]+dp[i]+dp[i+1])%MOD;
            dp=ndp;
            ndp.assign(m+2,0LL);
        }
        else{
            wv = (dp[x-1]+dp[x]+dp[x+1])%MOD;
            ans = (ans*wv)%MOD;
            dp.assign(m+2,0);
            dp[x]=1LL;
        }
    }
    if(x==0){
        ll sum=0LL;
        for(int i=1; i<=m; i++) sum = (sum + dp[i])%MOD;
        ans = (ans*sum)%MOD;
    }
    cout<<ans;
}