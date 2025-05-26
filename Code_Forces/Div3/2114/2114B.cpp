#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        // code
        int n,k,N0=0,N1=0;
        cin>>n>>k;
        string S;
        cin>>S;
        for(auto s : S){
            if(s=='1') N1++;
            else N0++;
        }
        n/=2;
        bool ans = (N0>= n-k) && (N1 >= n-k);
        if(!ans) cout<<"NO\n";
        else{
            ans = !((N0-n+k)&1);
            ans = ans && !((N1-n+k)&1);
            if(ans) cout << "YES\n";
            else cout<<"NO\n";
        }
    }
}