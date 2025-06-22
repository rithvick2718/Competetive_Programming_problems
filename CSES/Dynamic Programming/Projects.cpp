#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<tuple<int,int,ll>> bap(n); // bap[i] = {b[i],a[i],p[i]} b[i] is end day, a[i] is start day, p[i] is price
    for(int i=0; i<n; i++) cin>>get<1>(bap[i])>>get<0>(bap[i])>>get<2>(bap[i]); // taking in b[i],a[i],p[i] in order
    sort(bap.begin(),bap.end());
    vector<ll> dp(n,0); // our answer is dp[n-1];
    tuple<int,int,ll> t; // this is a help variable I use to perform binary search
    int j; // the position I need to work with after performing binary search
    vector<tuple<int,int,ll>>::iterator it; // iterator that helps with binary search
    dp[0] = get<2>(bap[0]); // base case of dp
    for(int i=1; i<n; i++){
        t = {get<1>(bap[i]),0,0LL}; // basically a[i], 0, 0
        it = lower_bound(bap.begin(),bap.end(),t); // so *it = {b[k],a[k],p[k]} such that a[i]<=b[k] so b[k-1]<a[i] , j=k-1
        j = it - bap.begin()-1;
        if(j==-1) dp[i]=max(dp[i-1],get<2>(bap[i])); // I cannot access dp[-1]
        else dp[i]=max(dp[i-1],dp[j]+get<2>(bap[i])); // also a[i]<=b[i] for all i so j<n always.
    }
    cout<<dp[n-1];
}