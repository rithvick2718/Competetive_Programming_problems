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
        int n;
        cin>>n;
        vector<pair<ll,ll>> to_multiply(n);
        vector<ll> to_add(n);
        char c;
        ll d;
        for(int i=0; i<n; i++)
        {
            to_add[i]=0;
            cin>>c;
            if(c=='+'){
                to_multiply[i].first=1;
                cin>>d;
                to_add[i]+=d;
            }
            else{
                cin>>to_multiply[i].first;
            }
            cin>>c;
            if(c=='+'){
                to_multiply[i].second=1;
                cin>>d;
                to_add[i]+=d;
            }
            else{
                cin>>to_multiply[i].second;
            }
        }
        pair<ll,ll> XY={1LL,1LL};
        if(n>1){
            vector<bool> a(n-1,true);
            a[n-2]=to_multiply[n-1].first>to_multiply[n-1].second;
            for(int i=n-3; i>=0;i--){
                if(to_multiply[i+1].first>to_multiply[i+1].second) a[i]=true;
                else if(to_multiply[i+1].first==to_multiply[i+1].second) a[i]=a[i+1];
                else a[i]=false;
            }
            ll T;
            for(int i=0; i<n-1; i++)
            {
                T=XY.first*(to_multiply[i].first-1)+XY.second*(to_multiply[i].second-1)+to_add[i];
                if(a[i]) XY.first+=T;
                else XY.second+=T;
            }
            cout<<(XY.first*to_multiply[n-1].first)+(XY.second*to_multiply[n-1].second)+to_add[n-1]<<"\n";
        }
        else{
            cout<<(XY.first*to_multiply[n-1].first)+(XY.second*to_multiply[n-1].second)+to_add[n-1]<<"\n";
        }
    }
}