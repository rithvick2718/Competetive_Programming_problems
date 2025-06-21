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
         vector<vector<ll>> dp(2,vector<ll>(SUM/2+1,0LL));
        int i=0,j=1;
        dp[i][0]=1LL;
        for(int n = 1; n<N; n++){
            for(int sum =0; sum<n; sum++){
                dp[j][sum]=dp[i][sum];
            }
            for(int sum =n ;sum <=SUM/2; sum++){
                dp[j][sum]=(dp[i][sum-n]+dp[i][sum])%MOD;
            }
            i=(i+1)%2;
            j=(j+1)%2;
        }
        cout<<dp[i][SUM/2];
    }
}