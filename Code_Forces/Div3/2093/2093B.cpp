#include<bits/stdc++.h>
using namespace std;
int ans(string n){
    int len=n.length();
    int ans=0;
    int i=len-1;
    for(;i>=0; i--)
    {
        if(n[i]=='0') ans++;
        else break;
    }
    i--;
    for(;i>=0; i--)
    {
        if(n[i]!='0') ans++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        string n;
        cin>>n;
        cout<<ans(n)<<"\n";
    }
}