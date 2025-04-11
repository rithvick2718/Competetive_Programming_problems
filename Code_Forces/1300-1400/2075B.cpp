#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin>>a[i];
        if(n==2){
            cout<<a[0]+a[1]<<"\n";
        }
        else if(k==1){
            auto it = max_element(a.begin()+1,a.end()-1);
            cout<<max(*(it)+max(a[0],a[n-1]),a[0]+a[n-1])<<"\n";
        }
        else{
            sort(a.rbegin(),a.rend());
            long long ans=0;
            for(int i=0; i<k+1; i++) ans+=a[i];
            cout<<ans<<"\n";
        }
    }
}