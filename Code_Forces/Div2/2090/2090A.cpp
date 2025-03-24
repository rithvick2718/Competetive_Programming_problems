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
        //code
        int x,y,a;
        cin>>x>>y>>a;
        a=a%(x+y);
        if(x<=a) cout<<"YES\n";
        else cout<<"NO\n";
    }
}