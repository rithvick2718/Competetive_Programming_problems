#include<bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007LL
#define ll long long
int main()
{
    vector<ll> dp(1'000'002,0);
    vector<ll> sum(1'000'002,0);
    dp[0]=1;
    sum[0]=1;
    dp[1]=2;
    sum[1]=3;
    for(int i=2; i<1'000'002; i++){
        dp[i]=(4*dp[i-1]+sum[i-1]-3LL*sum[i-2])%MOD;
        if(dp[i]<0LL) dp[i]+=MOD;
        sum[i]=(sum[i-1]+dp[i])%MOD;
    }
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}