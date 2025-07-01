#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> xm(n);
        vector<int> nm(n);
        for(int i=0; i<n; i++) cin>>a[i];
        nm[0]=a[0];
        for(int i=1; i<n; i++) nm[i] = min(a[i],nm[i-1]);
        xm[n-1]=a[n-1];
        for(int i =n-2; i>=0; i--) xm[i] = max(a[i],xm[i+1]);
        int mn = nm[n-1];
        int mx = xm[0];
        vector<bool> ans(n);
        cout<<1;
        for(int i=1; i<n-1; i++){
            ans[i] = (a[i]==mn) || (a[i]==mx) || (a[i]==nm[i]) || (a[i]==xm[i]);
            if(ans[i]) cout<<1;
            else cout<<0;
        }
        cout<<1<<"\n";
    }
}