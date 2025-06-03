#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,x,ans;
    cin>>tt;
    while(tt--){
        //code
        cin>>x;
        ans=1;
        while(x>=1){
            ans+=2;
            x>>=1;
        }
        cout<<ans<<"\n";
    }
}