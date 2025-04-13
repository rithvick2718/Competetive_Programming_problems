#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m,l,r;
        cin>>n>>m>>l>>r;
        if(m<=r) cout<<0<<" "<<m<<"\n";
        else cout<<r-m<<" "<<r<<"\n";
    }
}