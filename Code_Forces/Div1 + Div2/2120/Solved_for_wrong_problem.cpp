#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long binserK(long long n, long long m) {
    if(m == n-1) return 1;
    if( m == n*(n-1)/2 ) return n-1;
    long long lo = 0, hi = n, ans = -1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        ll lhs = (ll)mid * n - (ll)mid * (mid + 1) / 2;
        ll rhs = (ll)(mid + 1) * n
                     - (ll)(mid + 1) * (mid + 2) / 2;
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
        if(m<n-1 || m > (n*(n-1))/2 ) cout<<-1<<"\n";
        else{
            ll k;
            k = binserK(n,m);
            // cout<<"K is"<<k<<"\n \n";
            ll p = m + ((k*(k+1))/2LL) - n*k;
            cout<<1<<"\n";
            for(ll i =1LL; i<=k; i++){
                cout<<i<<" "<<i+1LL<<"\n";
            }
            ll i = k+2;
            for(ll rep = 0; rep < n-k-1-p; rep++) cout<<k<<" "<<i+rep<<"\n";
            i = n-p+1;
            for(ll rep = 0; rep < p; rep++) cout<<k+1<<" "<<i+rep<<"\n";            
        }
    }
}