#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
vector<ll> factorials(5'00'001); //factorials[i] = i!
vector<ll> invfactorials(5'00'001); //invfactorials[i] = (i!)^-1 (mod p) 
void precompute_f()
{
    factorials[0]=1LL; //0!=1
    for(ll i=1; i<5'00'001LL; i++)
    {
        factorials[i]=(factorials[i-1]*i)%mod;
    }
    return;
}
ll inv(ll n)
{
    ll pwr=mod-2;
    ll ans=1LL;
    ll y= n;
    while(pwr!=0){
        if(pwr&1) ans=(ans*y)%mod;
        y=(y*y)%mod;
        pwr>>=1;
    }
    return ans;
}
void precompute_if()
{
    invfactorials[0]=1; // inverse of 0!=1 is 1 in p
    for(int i=1; i<5'00'000; i++)
    {
        invfactorials[i]=(invfactorials[i-1]*inv(i))%mod;
    }
}
ll countSubsets(vector<ll>& nums, ll n, ll k) {
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    
    // Base case: There's always one subset (empty set) with sum 0
    for (ll i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    // Fill the DP table
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= k; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][k];
}
ll no_each_case(vector<ll> &c, ll sum)
{
    ll ans = factorials[sum/2];
    ans=(ans*ans)%mod;
    if(sum&1) ans=(ans*((sum+1)/2))%mod;
    for(auto x : c)
    {
        ans=(ans*invfactorials[x])%mod;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_f(); //O(n)
    precompute_if(); //O(n)
    int tt;
    cin>>tt;
    while (tt--)
    {
        vector<ll> c;
        ll input,sum=0LL;
        for(int i=0; i<26; i++)
        {
            cin>>input;
            sum+=input;
            if(input!=0LL) c.push_back(input);
        }
        cout<<(countSubsets(c,(ll)c.size(),(sum+1)/2)*no_each_case(c,sum))%mod<<"\n";
    }
}