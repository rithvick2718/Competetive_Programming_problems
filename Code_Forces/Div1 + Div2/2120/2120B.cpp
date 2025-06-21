#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,s;
        cin>>n>>s;
        int x,y;
        int dx,dy;
        int ans=0;
        for (int i = 0; i < n; i++)
        {
            cin>>dx>>dy; // this is important
            cin>>x>>y;
            if((dx == 1 && dy == 1) || (dx == -1 && dy == -1)){
                if(x==y) ans++;
            }
            else{
                if(x+y==s) ans++;
            }
        }
        cout<<ans<<"\n";
    }
}