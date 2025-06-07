#include<bits/stdc++.h>
using namespace std;
int main()
{
    string r,s;
    cin>>r>>s;
    int n=r.length();
    int m=s.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0; i<=n; i++) dp[i][0]=i;
    for(int j=0; j<=m; j++) dp[0][j]=j;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(r[i-1]==s[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min({1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]});
            }
        }
    }
    cout<<dp[n][m];
}