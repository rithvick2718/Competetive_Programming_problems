#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,j,k;
        cin>>n>>j>>k;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int tc = a[j-1];
        if(k>1) cout<<"YES\n";
        else{
            int mx =0; 
            for(auto x : a) mx = max(mx,x);
            if(tc == mx ) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}