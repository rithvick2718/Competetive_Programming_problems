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
        vector<int> pos(26,0);
        string S;
        cin>>S;
        for(auto s : S) pos[s-'a']++;
        int gt2=0,et2=0;
        for(auto p : pos){
            if(p>2){
                gt2++;
                et2++;
            }
            else if(p==2) et2++;
        }
        if(gt2>0 || et2>1) cout<<"YES\n";
        else if(et2==1 && S[0]!=S[n-1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}