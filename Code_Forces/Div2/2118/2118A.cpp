#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            if(i<k) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
    }
}