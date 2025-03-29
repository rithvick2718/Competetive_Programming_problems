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
        //code
        int n,m;
        cin>>n;
        int mn= 1000000001;
        int mx= 0;
        while(n--)
        {
            cin>>m;
            mn=min(mn,m);
            mx=max(mx,m);
        }
        cout<<mx-mn<<"\n";
    }
}