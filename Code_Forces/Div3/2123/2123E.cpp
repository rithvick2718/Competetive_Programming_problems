#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n), cnt(n+2, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] <= n) 
                cnt[a[i]]++;
        }
        vector<bool> feasible(n+2, true);
        for(int x = 1; x <= n+1; x++){
            feasible[x] = feasible[x-1] && (cnt[x-1] > 0);
        }
        vector<ll> diff(n+2, 0);
        for(int x = 0; x <= n+1; x++){
            if(!feasible[x]) continue;
            ll L = (x <= n ? cnt[x] : 0);// must remove all x’s
            ll R = n - x; 
            if(L <= R){
                diff[L] += 1;
                diff[R+1] -= 1;
            }
        }
        vector<ll> ans(n+1, 0);
        ll cur = 0;
        for(int k = 0; k <= n; k++){
            cur += diff[k];
            ans[k] = cur;
        }
        for(int k = 0; k <= n; k++){
            cout << ans[k] << (k==n ? '\n' : ' ');
        }
    }
    return 0;
}
