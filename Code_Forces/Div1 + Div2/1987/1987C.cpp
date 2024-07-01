#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int h[n];
        for(int i=0; i<n; i++)
        {
            cin>>h[i];
        }
        int dp = h[n-1];
        for(int i=n-2; i>=0; i--)
        {
            dp=max(dp+1,h[i]);
        }
        cout<<dp<<"\n";
    }
}