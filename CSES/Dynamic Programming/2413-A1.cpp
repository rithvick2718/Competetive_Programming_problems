#include<bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007LL
#define ll long long
int main()
{
    vector<int> dp(1'000'002,0);
    dp[0]=1;
    dp[1]=2;
    dp[2]=8;
    for(int i=3; i<1'000'002; i++){
        dp[i]=(6LL*dp[i-1]-7LL*dp[i-2])%MOD;
        if(dp[i]<0) dp[i]+=MOD;
    }
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}