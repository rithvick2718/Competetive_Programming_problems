#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1'000'000'007LL

vector<ll> f_inv(100'001);

void fill_inv();
ll inv_cal(ll n);
ll nCr(ll n, ll r);

ll nCr (ll n, ll r){
    ll ans = n;
    for(ll k =1; k<r; k++) ans = (ans * (n-k))%MOD;
    ans = (ans * f_inv[r])%MOD;
    return ans;
}
ll inv_cal(ll n){
    ll pwr =MOD-2;
    ll to_multiply = n;
    ll ans = 1LL;
    while(pwr>0){
        if(pwr&1) ans=(ans*to_multiply)%MOD;
        to_multiply=(to_multiply*to_multiply)%MOD;
        pwr>>=1;
    }
    return ans;
}
void fill_inv(){
    f_inv[0]=1;
    f_inv[1]=1;
    for(ll i = 2LL; i<100'001LL; i++) f_inv[i] = (f_inv[i-1]*inv_cal(i))%MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill_inv();
    int tt;
    cin>>tt;
    while(tt--){
        ll a,b,k;
        cin>>a>>b>>k;
        ll n = ((a-1)*(k)+1)%MOD;
        ll m =( ( ( k * nCr(n,a) ) % MOD ) * (b-1) + 1LL )%MOD;
        cout<<n<<" "<<m<<"\n";
    }
}