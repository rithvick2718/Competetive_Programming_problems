#include<iostream>
#include<vector>
using ll = long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> x(n);
    vector<ll> presum(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
        presum[i+1]=presum[i]+x[i];
    }
    vector<ll> dp(n,0);
    for(int r=0; r<n; r++){
        dp[r]=x[r];
        for(int l=r-1; l>=0; l--){
            dp[l]=max(x[r]+(presum[r]-presum[l])-dp[l],x[l]+(presum[r+1]-presum[l+1])-dp[l+1]);
        }
    }
    cout<<dp[0];
}