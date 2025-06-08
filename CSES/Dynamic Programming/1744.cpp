#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e6));
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i!=j){
                for(int k=0; k<=i; k++)
                    dp[i][j]=min(1+dp[k][j]+dp[i-k][j],dp[i][j]);
                for(int k=0; k<=j; k++)
                    dp[i][j]=min(1+dp[i][k]+dp[i][j-k],dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    cout<<dp[a][b];
}