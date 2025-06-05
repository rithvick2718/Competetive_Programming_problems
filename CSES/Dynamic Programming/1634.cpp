#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    vector<int> dp(x+1,x+1);
    dp[0]=0;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i-coins[j]>=0) dp[i]=min(dp[i],1+dp[i-coins[j]]);
        }
    }
    if(dp[x]<=x) cout<<dp[x];
    else cout<<-1;
}