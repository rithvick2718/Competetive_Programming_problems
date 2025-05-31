#include<bits/stdc++.h>
using namespace std;
#define MOD 998'244'353LL
#define ll long long
int t_pwr(int n)
{
    ll to_multiply =2LL;
    ll ans=1LL;
    while(n>=1){
        if(n&1) ans=(ans*to_multiply)%MOD;
        to_multiply=(to_multiply*to_multiply)%MOD;
        n>>=1;
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
        ll n;
        cin>>n;
        vector<ll> p(n),q(n),r(n),p1(n),q1(n),p_p(n),q_q(n);
        cin>>p[0];
        p1[0]=p[0];
        p_p[0]=0;
        for(ll i=1LL; i<n; i++){
            cin>>p[i];
            if(p[i]>p1[i-1]){
                p_p[i]=i;
                p1[i]=p[i];
            }
            else{
                p_p[i]=p_p[i-1];
                p1[i]=p1[i-1];
            }
        }
        cin>>q[0];
        q1[0]=q[0];
        q_q[0]=0;
        for(ll i=1LL; i<n; i++){
            cin>>q[i];
            if(q[i]>q1[i-1]){
                q_q[i]=i;
                q1[i]=q[i];
            }
            else{
                q_q[i]=q_q[i-1];
                q1[i]=q1[i-1];
            }
        }
        for(int i=0; i<n; i++)
        {
            if(p1[i]>q1[i]){
                r[i]=(t_pwr(p1[i])+t_pwr(q[i-p_p[i]]))%MOD;
            }
            else if(p1[i]<q1[i]){
                r[i]=(t_pwr(q1[i])+t_pwr(p[i-q_q[i]]))%MOD;
            }
            else{
                r[i] = (t_pwr(p1[i]) +  t_pwr(max(p[i-q_q[i]],q[i-p_p[i]])))%MOD;
            }
        }
        for(int i=0; i<n-1; i++) cout<<r[i]<<" ";
        cout<<r[n-1]<<"\n";
    }
}