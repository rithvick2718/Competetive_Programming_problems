#include<bits/stdc++.h>
using namespace std;
#define ll long long
int BRIAN(ll n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
ll l2(ll n){
    ll ans=1LL;
    while(n>0){
        ans<<=1;
        n>>=1;
    }
    return ans-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,a;
        ll k;
        cin>>n>>k;
        vector<ll> costs;
        int ans=0;
        for(int i=0; i<n; i++){
            cin>>a;
            ans+=BRIAN(a);
            ll c =1LL;
            for(int j=0; j<60; j++){
                if(a%2==0){
                    costs.push_back(c);
                }
                a>>=1;
                c<<=1;
            }
        }
        sort(costs.begin(),costs.end());
        for(auto cost : costs){
            if(k>=cost){
                k-=cost;
                ans++;
            }
            else break;
        }
        cout<<ans<<"\n";
    }
}