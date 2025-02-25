#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k;
        cin>>n>>k>>p;
        if(k<0) k=-k;
        int ans = k/p;
        if(k%p!=0) ans++;
        if (ans<=n) cout<<ans<<"\n";
        else cout<<-1<<"\n";
    }
}