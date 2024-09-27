#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        ll n,q;
        cin>>n>>q;
        map<ll,ll> mp;
        int x1,x2;
        cin>>x1;
        for(int i=1; i<n; i++) //p1
        {
            cin>>x2;
            mp[(ll)i*(ll)(n-i)]+=x2-x1-1;
            x1=x2;
        } //fine!!
        mp[n-1]+=2;
        for(int i=2; i<=n-1;i++)
        {
            mp[(ll)(i-1)*(n-i)+(n-1)]++;
        }
        ll k;
        for(int i=0; i<q; i++)
        {
            cin>>k;
            cout<<mp[k]<<" ";
        }
        cout<<"\n";
    }
}