#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int a,x,y;
        cin>>a>>x>>y;
        if((a<x && a<y) || (a>x && a>y)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}