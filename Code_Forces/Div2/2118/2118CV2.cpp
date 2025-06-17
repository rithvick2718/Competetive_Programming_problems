#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n;
    cin>>tt;
    vector<ll> twpr(62);
    vector<ll> freq(62);
    ll k;
    int ans;
    ll in=1LL;
    for(int i=0; i<62; i++){
        twpr[i]=in;
        in<<=1;
    }
    while(tt--){
        ans=0;
        freq.assign(62,0);
        cin>>n>>k;
        for(int take =0; take<n; take++){
            cin>>in;
            for(int i=0; i<62; i++){
                if(in&1) ans++;
                else{
                    freq[i]++;
                }
                in>>=1;
            }
        }
        int i=0;
        while(i<62){
            if(k/twpr[i]>=freq[i]){
                k-=twpr[i]*freq[i];
                ans+=freq[i];
            }
            else{
                ans+=k/twpr[i];
                break;
            }
            i++;
        }
        cout<<ans<<"\n";
    }
}