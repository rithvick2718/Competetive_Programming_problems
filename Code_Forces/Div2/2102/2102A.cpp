#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m,p,q;
        cin>>n>>m>>p>>q;
        if(n%p!=0) cout<<"YES\n";
        else{
            if(m==q*(n/p)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}