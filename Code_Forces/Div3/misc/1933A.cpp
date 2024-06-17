#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a;
        int ans=0;
        while (n--)
        {
            cin>>a;
            if(a>0) ans =ans+a;
            else ans =ans -a;
        }
        cout<<ans<<"\n";
    }
}