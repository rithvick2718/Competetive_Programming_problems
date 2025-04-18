#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print_v(const vector<ll> &V){
    for(auto v : V) cout<<v<<" ";
    cout<<"\n";
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // Splitmix64 hash function — fast and high quality
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(long long x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
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
        unordered_set<ll,custom_hash> s;
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