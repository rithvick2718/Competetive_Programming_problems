#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> p(n);
    vector<tuple<int,int,ll>> bap(n);
    for(int i=0; i<n; i++) cin>>get<1>(bap[i])>>get<0>(bap[i])>>get<2>(bap[i]);
    sort(bap.begin(),bap.end());
    vector<ll> dp(n,0);
    tuple<int,int,ll> t;
    int j;
    vector<tuple<int,int,ll>>::iterator it;
    dp[0] = get<2>(bap[0]);
    for(int i=1; i<n; i++){
        t = {get<1>(bap[i]),0,0LL}; // basically a[i], 0, 0
        it = lower_bound(bap.begin(),bap.end(),t); // so *it = {b[j],a[j],p[j]} such that a[i]<=b[j] so b[j-1]<a[i]
        j = it - bap.begin()-1;
        if(j==-1) dp[i]=max(dp[i-1],get<2>(bap[i]));
        else dp[i]=max(dp[i-1],dp[j]+get<2>(bap[i]));
    }
    cout<<dp[n-1];
}