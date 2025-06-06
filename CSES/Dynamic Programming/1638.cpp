#include<bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(n,0));
    char c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>c;
            if(c=='*')
                dp[i][j]=-1;
        }
    }
    // print_vv(is_occupied);
    if(dp[0][0]!=-1) dp[0][0]=1;
    for(int sum = 0; sum<=2*n-2; sum++){
        for(int i=0; i<=sum && i<n ; i++){
            if(sum-i<n){
                if(dp[i][sum-i]==-1) {/*do nothing*/}
                else{
                    if(i-1>=0) if(dp[i-1][sum-i]!=-1) dp[i][sum-i]=(dp[i][sum-i]+dp[i-1][sum-i])%MOD;
                    if(sum- i - 1>=0) if(dp[i][sum-i-1]!=-1) dp[i][sum-i]=(dp[i][sum-i]+dp[i][sum-i-1])%MOD;
                }
            }
        }
    }
    if(dp[0][0]!=-1 && dp[n-1][n-1]!=-1) cout<<dp[n-1][n-1];
    else cout<<0;
} 