#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        vector<bool> s(n,false);
        char c;
        int ones=0;
        for(int i=0; i<n; i++){
            cin>>c;
            if(c=='1'){
                 s[i]=true;
                 ones++;
            }
        }
        if(ones<=k) cout<<"Alice\n";
        else if (n>=2*k) cout<<"Bob\n";
        else{
            int zc=0;
            int mx=0;
            for(int i=0; i<n; i++){
                if(s[i]){
                    mx = max(zc,mx);
                    zc=0;
                }
                else zc++;
            }
            mx =max(mx,zc);
            if(mx<k) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
    }
}