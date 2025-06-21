#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; //n>=1
    cin>>n;
    vector<ll> x(n+1,-LONG_LONG_MAX);
    vector<ll> presum(n+1,0);
    for(int i=0; i<n; i++){
        cin>>x[i];
        presum[i+1]=presum[i]+x[i];
    }
    vector<vector<ll>> dp(n+2, vector<ll>(n+2,0LL));
    dp[0][0]=x[0];
    dp[0][1]=max(x[0],x[1]);
    dp[1][1]=x[1];
    for(int r=2; r<n; r++){
        dp[r][r]=x[r];
        dp[r-1][r]=max(x[r-1],x[r]);
        for(int l=r-2; l>=0; l--){
            dp[l][r]=max(x[r]+presum[r]-presum[l]-dp[l][r-1],x[l]+presum[r+1]-presum[l+1]-dp[l+1][r]);
        }
    }
    cout<<dp[0][n-1];
}