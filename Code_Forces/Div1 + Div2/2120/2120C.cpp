#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll binserK(ll n, ll m) {
    if(m == n) return 1LL;
    if( m == n*(n+1)/2 ) return n;
    long long lo = 0, hi = n, ans = -1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        ll lhs = mid*n-((mid)*(mid-1))/2;
        ll rhs = (mid+1)*n-((mid)*(mid+1))/2;
        if (lhs <= m && m < rhs) {
            ans = mid;
            break;
        } else if (m < lhs) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        ll n,m;
        cin>>n>>m;
        if(m<n || m > (n)*(n+1LL)/2LL) cout<<-1<<"\n";
        else{
            ll k =binserK(n,m);
            if(m == n*k - (k*(k-1))/2LL){
                cout<<k<<"\n";
                for(ll i=1LL; i<=n; i++) if (i!=k) cout<<k<<" "<<i<<"\n";
            }
            else{
                cout<<k+1<<"\n";
                for(ll i= 1LL; i<=k; i++) cout<<k+1<<" "<<i<<"\n";
                m -=n*k - (k*(k-1))/2LL+1LL;
                for(ll rep =0LL; rep<m; rep++) cout<<k+1<<" "<<k+2+rep<<"\n";
                for(ll rep =k+2+m; rep<=n; rep++) cout<<k<<" "<<rep<<"\n";
            }
        }
    }
}