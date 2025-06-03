#include<bits/stdc++.h>
using namespace std;
#define ll long long
void prll_v(const vector<ll> &V){
    for(auto v : V) cout<<v<<" ";
    cout<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt,n;
    cin>>tt;
    while(tt--){
        cin>>n;
        vector<ll> a;
        vector<ll> mn_p;
        vector<ll> mx_p;
        ll input,prev;
        cin>>input;
        prev=input;
        a.push_back(input);
        mn_p.push_back(0);
        mx_p.push_back(0);
        for(ll i=1; i<n; i++){
            cin>>input;
            if(prev==input) mx_p.back()=i;
            else{
                prev=input;
                a.push_back(input);
                mn_p.push_back(i);
                mx_p.push_back(i);
            }
        }
        // prll_v(a);
        // prll_v(mn_p);
        // prll_v(mx_p);
        // cout<<a.size()<<" "<<mn_p.size()<<"\n";
        ll mn = 9223372036854775807;
        ll m = a.size();
        for(ll i=0; i<m; i++){
            mn = min(mn,a[i]*(mn_p[i])+a[i]*(n-1-mx_p[i]));
        }
        cout<<mn<<"\n";
    }
}