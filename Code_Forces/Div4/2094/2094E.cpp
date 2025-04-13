#include<bits/stdc++.h>
#define ll long long
using namespace std;
void update(vector<ll> &ones, ll a)
{
    int i=0;
    while(a>0){
        if(a&1) ones[i]++;
        i++;
        a>>=1;
    }
    return;
}
ll calculate(vector<ll> ones, ll n, ll a)
{
    ll ans=0LL;
    ll to_multiply=1LL;
    int i=0;
    while(a>0){
        if(a&1){ //here we have a 1 so we will have ( n-ones[i] )
            ans+=(n-ones[i])*to_multiply;
        }
        else{
            ans+=(ones[i])*to_multiply;
        }
        i++;
        a>>=1;
        to_multiply<<=1;
    }
    for(; i<33; i++)
    {
        ans+=(ones[i])*to_multiply;
        to_multiply<<=1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        vector<ll> ones(33,0);
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            update(ones,a[i]);
        }
        ll mx=0LL;
        for(int i=0; i<n; i++)
        {
            mx=max(mx,calculate(ones,n,a[i]));
        }
        cout<<mx<<"\n";
    }
}