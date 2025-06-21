#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1'000'000'007LL
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int SUM = (N)*(N+1)/2;
    if(SUM&1) cout<<0;
    else{
        vector<ll> dp(SUM/2+1);
        dp[0]=1LL;
        for(int n = 1; n<N; n++){
            for(int sum =SUM/2 ;sum >=n; sum--){
                dp[sum]=(dp[sum-n]+dp[sum])%MOD;
            }
        }
        cout<<dp[SUM/2];
    }
}