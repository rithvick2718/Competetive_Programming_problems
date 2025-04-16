#include<bits/stdc++.h>
using namespace std;
#define mod 998244353LL
#define ll long long
vector<ll> make_o(const vector<int> &A){
    ll o =0LL;
    vector<ll> O;
    for(auto a : A){
        if(a==1) o++;
        if(a==2) O.push_back(o); 
    }
    return O;
}
vector<ll> make_t(const vector<int> &A){
    ll t =0LL;
    vector<ll> T;
    int n =A.size();
    for(int i=n-1; i>=0; i--){
        if(A[i]==3) t++;
        if(A[i]==2) T.push_back(t);
    }
    if(T.size()==0) return T;
    reverse(T.begin(),T.end());
    return T;
}
void print_v(vector<ll> A)
{
    for(auto a : A) cout<<a<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const ll inv_2 = 499122177LL; // basically (mod+1)/2
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        vector<ll> o =make_o(a);
        vector<ll> t = make_t(a);
        // print_v(o);
        // print_v(t);
        if(o.size()!=0){
            ll y=1LL;
            ll p_c =0LL;
            for(int i=1; i<t.size(); i++)
            {
                p_c=(p_c+(y*t[i]))%mod;
                y=(2LL*y)%mod;
            }
            ll ans=0;
            n=o.size();
            for(int i=0; i<n-1; i++){
                ans=(ans+o[i]*t[i])%mod;
                ans=(ans+o[i]*p_c)%mod;
                p_c=(p_c-t[i+1])%mod;
                if(p_c<0) p_c+=mod;
                p_c=(inv_2*p_c)%mod;
            }
            ans=(ans+(o[n-1]*t[n-1]))%mod;
            cout<<ans<<"\n";
        }
        else cout<<0<<"\n";
    }
}