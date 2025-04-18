#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print_v(const vector<ll> &V){
    for(auto v : V) cout<<v<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin>>a[i]; // got the arr
        vector<ll> total_sum(n+1),even_sum(n+1);
        total_sum[0]=0;
        even_sum[0]=0;
        for(int i=1; i<=n; i++){
            total_sum[i]=total_sum[i-1]+a[i-1];
            even_sum[i]=even_sum[i-1];
            if(!(i&1)) even_sum[i]+=a[i-1];
        }
        set<ll> s;
        bool found =false;
        for(int i=0; i<=n; i++)
        {
            if(s.count(total_sum[i]-2*even_sum[i])==0) s.insert(total_sum[i]-2*even_sum[i]);
            else{
                found=true;
                break;
            }
        }
        if(found) cout<<"YES\n";
        else cout<<"NO\n";
    }
}