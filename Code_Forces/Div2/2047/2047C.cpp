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
        vector<int> r1(n),r2(n);
        for(int i=0; i<n; i++) cin>>r1[i];
        for(int i=0; i<n; i++) cin>>r2[i];
        for(int i=0; i<n; i++){
            if(r1[i]>r2[i]) swap(r1[i],r2[i]);
        }
        int ans =0;
        for(auto r : r2) ans+=r;
        vector<int>::iterator it = max_element(r1.begin(),r1.end());
        ans+=(*it);
        cout<<ans<<"\n";
    }
}