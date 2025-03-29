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
        int n;
        long long m,mx=0,ans=0LL;
        int e=0,o=0;
        cin>>n;
        while(n--)
        {
            cin>>m;
            if(m&1) o++;
            else e++;
            ans+=m-(m%2);
            mx=max(mx,m);
        }
        if(e>0 && o>0) cout<<ans+1<<"\n";
        else cout<<mx<<"\n";
    }
}