#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n;
    cin>>tt;
    while(tt--)
    {
        //code
        cin>>n;
        int h,w;
        int mx_h=0,mx_w=0;
        while (n--)
        {
            cin>>h>>w;
            mx_h=max(mx_h,h);
            mx_w=max(mx_w,w);
        }
        cout<<2*mx_h+2*mx_w<<"\n";
    }
}