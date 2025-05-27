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
        int n,ans=1,prv,nxt;
        cin>>n>>prv;
        for (int i = 1; i < n; i++)
        {
            cin>>nxt;
            if(nxt>1+prv){
                ans++;
                prv=nxt;
            }
        }
        cout<<ans<<"\n";
    }
}