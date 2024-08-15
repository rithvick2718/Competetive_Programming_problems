#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int l,r,L,R;
    while(t--)
    {
        //code
        cin>>l>>r>>L>>R; //l<r && L<R
        if(r<L || R<l) cout<<1<<"\n"; // simplest case
        else{
            int ans=0;
            if(l!=L) ans++;
            if(r!=R) ans++;
            if(ans == 0) // l==L and r==R
            {
                cout<<r-l<<"\n";
            }
            else if(ans == 1) // exactly one bound is same
            {
                if(l==L) cout<<ans+ min(r-l,R-l)<<"\n";
                else cout<<ans+ min(r-l,r-L)<<"\n";
            }
            else
            {
                cout<<2+min({abs(l-R),abs(L-r),abs(l-r),abs(L-R)})<<"\n";
            }
        }
    }
}