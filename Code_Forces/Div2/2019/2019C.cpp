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
        ll n,k;
        cin>>n>>k;
        ll a, mx=-1,sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            if(a>mx) mx=a;
            sum+=a;
        }
        for(ll h=n; h>=1; h--) // h<=h
        {
            if(h==1)
            {
                cout<<1<<"\n";
                break;
            }
            if((sum+k)/h >= mx && (sum+k)/h >= sum/h +(sum%h?1:0))
            {
                cout<<h<<"\n";
                break;
            }
        }
    }
}