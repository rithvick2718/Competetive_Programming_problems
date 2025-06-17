#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,k,a,b,x,y;
    cin>>tt;
    int n_a,n_b,ans;
    while(tt--){
        //code
        cin>>k>>a>>b>>x>>y;
        ans=0;
        if(x<y){
            ans+=max(0,(k-a)/x+(((k-a)%x)>=0 ? 1 : 0));
            k-=ans*x;
            ans+=max(0,(k-b)/y+(((k-b)%y)>=0 ? 1 : 0));
        }
        else{
            ans+=max(0,(k-b)/y+(((k-b)%y)>=0 ? 1 : 0));
            k-=ans*y;
            ans+=max(0,(k-a)/x+(((k-a)%x)>=0 ? 1 : 0));
        }
        cout<<ans<<"\n";
    }
}