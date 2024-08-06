#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,s,m;
    int l_last;
    int r_last;
    int l_p;
    int r_p;
    while(t--)
    {
        //code
        cin>>n>>s>>m;
        l_last=0;
        r_last=0;
        int mx_time=0;
        for(int i=0; i<n;i++)
        {
            cin>>l_p>>r_p;
            mx_time=max(l_p-r_last,mx_time);
            l_last=l_p;
            r_last=r_p;
        }
        mx_time=max(mx_time, m-r_last);
        if(mx_time>=s) cout<<"YES\n";
        else cout<<"NO\n";
    }
}