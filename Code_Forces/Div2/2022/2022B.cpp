#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n,x,a,mx,sum=0;
        cin>>n>>x;
        mx=-1;
        for (ll i = 0; i < n; i++) {
            cin >> a;
            if(a>mx) mx=a;
            sum+=a;
        }
        cout<<max(sum/x+(sum%x?1:0),mx)<<"\n";
    }
    return 0;
}
