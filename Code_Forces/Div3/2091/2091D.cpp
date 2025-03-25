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
        int n,m,k;
        cin>>n>>m>>k;
        if(k%n==0) k=k/n;
        else k=k/n+1;
        int ans;
        if(k%(m-k+1)==0) ans= k/(m-k+1);
        else ans= k/(m-k+1)+1;
        cout<<ans<<"\n";
    }
}