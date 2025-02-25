#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        char c;
        ll a=0LL , b=0LL;
        while(n--)
        {
            cin>>c;
            if(c=='-') a++;
            else b++;
        }
        ll ans=b*(a/2)*(a-(a/2));
        cout<<ans<<"\n";
    }
}