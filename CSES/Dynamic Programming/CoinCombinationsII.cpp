#include<bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin>>coins[i];
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=0; i<n; i++){
        for(int j=coins[i]; j<=x; j++){
            dp[j]=(dp[j]+dp[j-coins[i]])%MOD;
        }
    }
    cout<<dp[x];
}