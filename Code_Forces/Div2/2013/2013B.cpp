#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //test cases
    cin>>t;
    int n;
    while(t--)
    {
        //code
        cin>>n;
        ll ans=0;
        ll take;
        for(int i=0; i<n-2; i++)
        {
            cin>>take;
            ans+=take;
        }
        cin>>take;
        ans-=take;
        cin>>take;
        ans+=take;
        cout<<ans<<"\n";
    }
}