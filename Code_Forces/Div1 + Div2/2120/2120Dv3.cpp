#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1'000'000'007

void inv_fill();
ll inv_cal(ll n);
ll nCr (ll n, ll r);

ll inv_cal(ll n){
    ll pwr = MOD-2;
    ll to_multiply = n;
    ll ans = 1LL;
    while(pwr>0){
        if(pwr&1) ans = (ans * to_multiply)%MOD;
        to_multiply = (to_multiply * to_multiply)%MOD;
        pwr >>= 1;
    }
    return ans;
}
vector<ll> inverse(100'001);
void inv_fill()
{
    inverse[0]=1LL;
    inverse[1]=1LL;
    for(ll i = 2LL; i < 100'001LL; i++) inverse[i] = inv_cal(i);
    return;
}
ll nCr (ll n, ll r){
    ll ans = 1LL;
    for(ll k = 0LL; k < r; k++) ans = (ans * (n-k))%MOD;
    for(ll k =1LL; k<=r; k++) ans = ans * (inverse[k])%MOD;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    inv_fill();
    int tt;
    cin>>tt;
    while(tt--){
        ll a,b,k;
        cin>>a>>b>>k;
        ll n = ((a-1)*k+1)%MOD;
        ll m = k;
        m = (m * nCr(n,a))%MOD;
        m = (m*(b-1))%MOD;
        m = (m+1)%MOD;
        cout<<n<<" "<<m<<"\n";
    }
}