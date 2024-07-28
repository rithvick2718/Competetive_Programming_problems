#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n;
        cin>>n;
        int a,mx=0;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            if(i%2==0) mx = max(mx,a);
        }
        cout<<mx<<"\n";
    }
}