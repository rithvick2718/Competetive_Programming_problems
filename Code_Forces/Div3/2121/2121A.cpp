#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int mn =1000;
        int mx =0;
        int n,s;
        cin>>n>>s;
        int k;
        for (int i = 0; i < n; i++)
        {
            cin>>k;
            mn=min(mn,k);
            mx=max(mx,k);
        }
        if(s>=mx) cout<<s-mn<<"\n";
        else if(s>=mn) {
            cout<<min(2*mx-mn-s,s+mx-2*mn)<<"\n";
        }
        else cout<<mx-s<<"\n";
    }
}