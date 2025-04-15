#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        //code
        ll n,m;
        cin>>n>>m;
        vector<ll> a(m);
        for(int i=0; i<(int)m; i++) cin>>a[i]; // got a
        sort(a.begin(),a.end()); // sort a
        vector<ll> pre_sum(m); // make presum NOW
        pre_sum[0]=a[0];
        for(int i=1; i<m; i++){
            pre_sum[i]=a[i];
            pre_sum[i]+=pre_sum[i-1];
        } //done with presum
        int j;
        ll ans=0;
        for(int i=0; i<m-1; i++){
            j=lower_bound(a.begin(),a.end(),(ll)n-a[i])-a.begin();
            j=max(i+1,j);
            ans+=pre_sum[m-1]-pre_sum[j-1]-((ll)(m-j))*((ll)n-a[i]-1LL);
        }
        j=lower_bound(a.begin(),a.end(),(ll)n)-a.begin();
        ll J= (ll)j;
        ll M = (ll)m;
        ll extra = ((M)*(M-1LL) -(J)*(J-1LL))/2+(M-J)*(M-J-1LL)/2;
        ans-=extra;
        cout<<2LL*ans<<"\n";
    }
}