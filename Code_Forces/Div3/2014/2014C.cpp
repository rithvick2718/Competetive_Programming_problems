#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    ll n;
    while(t--)
    {
        //code
        cin>>n;
        ll a[n];
        ll sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(n==1 || n==2) cout<<-1<<"\n";
        else
        {
            nth_element(a,a+(n/2),a+n);
            ll x = 2*n*(a[(n/2)])-sum;
            if(x<0) cout<<0<<"\n";
            else cout<<x+1<<"\n";
        }
    }
}