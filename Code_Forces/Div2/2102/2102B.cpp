#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,first,a;
        cin>>n>>first;
        if(first<0) first*=-1;
        int count=0;
        for(int i=1; i<n; i++){
            cin>>a;
            if(a<0) a*=-1;
            if(first<=a) count++;
        }
        if(first==0) cout<<"YES\n";
        else{
            if(count>=n-((n+1)/2) || 1+count >= (n+1)/2) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}