#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        //code
        int n,x,y;
        map<pair<int,int>,ll> m;
        cin>>n>>x>>y;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            m[{a[i]%x,a[i]%y}]++;
        }
        int correct;
        ll ans=0;
        for(int i=0; i<n; i++){
            correct=(-a[i])%x;
            if(correct<0) correct+=x;
            ans+=m[{correct,a[i]%y}];
            if(correct==a[i]%x) ans--;
            m[{a[i]%x,a[i]%y}]--;
        }
        cout<<ans<<"\n";
    }
}