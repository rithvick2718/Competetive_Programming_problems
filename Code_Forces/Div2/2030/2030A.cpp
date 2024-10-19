#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        //code
        cin>>n;
        int a;
        int mn=1001;
        int mx=-1;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            mx=max(mx,a);
            mn=min(mn,a);
        }
        cout<<(n-1)*(mx-mn)<<"\n";
    }
}