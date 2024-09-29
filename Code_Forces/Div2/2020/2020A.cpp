#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        //code
        cin>>n>>k;
        int ans=0;
        if(k!=1)
        {
            while(n>0)
            {
                ans+=n%k;
                n/=k;
            }
            cout<<ans<<"\n";
        }
        else cout<<n<<"\n";
    }
}