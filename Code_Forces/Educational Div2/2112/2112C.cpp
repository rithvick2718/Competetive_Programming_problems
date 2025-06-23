#include<bits/stdc++.h>
using namespace std;
#define ll long long
int countIntersection(int j, int k, int l, int n) {
    int left  = max(j+1, l);
    int right = min(k-1, n-1);
    if (right < left) return 0;
    return right - left + 1;
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
        vector<int> a(n);
        ll ans=0LL;
        for(int i=0; i<n; i++) cin>>a[i]; //sorted
        int k,l;
        vector<int>::iterator it;        
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                it = lower_bound(a.begin(),a.end(),a[i]+a[j]); // the first element so that a[k] >= a[i] + a[j] so a[i] +a[j] > a[k-1]
                k = it - a.begin();
                it = upper_bound(a.begin(),a.end(),a[n-1]-a[i]-a[j]);
                l = it -a.begin();
                ans+=max(0LL, (ll)countIntersection(j,k,l,n));
            }
        }
        cout<<ans<<"\n";
    }
}