#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> process_block(const vector<ll> &b){
    ll n = b.size();
    vector<ll> l(n),r(n);
    r[0]=b[0];
    for(ll i=1; i<n; i++){
        r[i]=r[i-1];
        if(b[i]<b[i-1]) r[i]+=b[i];
        else r[i]+=b[i]-2*b[i-1]+1;
    }
    l[n-1]=b[n-1];
    for(ll i=n-2; i>=0 ; i--)
    {
        l[i]=l[i+1];
        if(b[i]<b[i+1]) l[i]+=b[i];
        else l[i]+=b[i]-2*b[i+1]+1;
    }
    ll c = 0;
    for(ll i=0 ; i<n ; i++){
        c=max(c,r[n-1]+l[0]-l[i]-r[i]+b[i]);
    }
    return {l[0],r[n-1],c};
}
void prll_blocks(const vector<vector<ll>> &B){
    for(auto b : B){
        for(auto n : b) cout<<n<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    return;
}
void prll_vectors(const vector<ll> & V){
    for(auto v : V) cout<<v<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt;
    cin>>tt;
    while(tt--){
        ll n,k;
        cin>>n>>k;
        vector<vector<ll>> B;
        ll a,b,c=1;
        cin>>a;
        while(a%2==0) {
            c<<=1;
            a>>=1;
        }
        b=a;
        B.push_back({c});
        for(ll i=1; i<n; i++){
            cin>>a;
            c=1;
            while(a%2==0) {
                c<<=1;
                a>>=1;
            }
            if(b==a) B.back().push_back(c);
            else {
                b=a;
                B.push_back({c});
            }
        }
        // prll_blocks(B);
        // so B (Blocks are complete)
        ll m = B.size();

        vector<ll> L(m),R(m),C(m);
        vector<ll> p;
        for(ll i=0; i<m; i++)
        {
            p=process_block(B[i]);
            L[i]=p[0];
            R[i]=p[1];
            C[i]=p[2];
        }
        for(ll i=1; i<m; i++) R[i]+=R[i-1];
        for(ll i=m-2; i>=0; i--) L[i]+=L[i+1];
        // cout<<"L is"; prll_vectors(L);
        // cout<<"R is"; prll_vectors(R);
        // cout<<"C is"; prll_vectors(C);
        ll ans=max(L[0],R[m-1]);
        for(ll i=0; i<m; i++){
            ans = max(ans,L[0]-L[i]+C[i]+R[m-1]-R[i]);
        }
        // cout<<ans<<" "<<k<<"\n";
        if(ans>=k) cout<<"YES\n";
        else cout<<"NO\n";
    }
}