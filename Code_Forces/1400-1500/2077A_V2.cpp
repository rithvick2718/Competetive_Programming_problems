#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<ll> b(2*n);
        for(int i=0; i<2*n; i++) cin>>b[i];
        sort(b.rbegin(),b.rend());
        vector<ll> a(2*n+1);
        for(int i=0; i<n; i++){
            a[2*i]=b[i];
            a[2*i+1]=b[n+1+i];
        }
        a[2*n]=b[n];
        a[2*n-1]=a[2*n];
        for(int i=0; i<=2*n-2; i++){
            if(i&1) a[2*n-1]-=a[i];
            else a[2*n-1]+=a[i];
        }
        for(auto i : a) cout<<i<<" ";
        cout<<"\n";
    }
}