#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int b[n];
        for(size_t i  =0; i<n; i++)
        {
            cin>>b[i];
        }
        int l=0,r=n-1;
        while(l<r)
        {
            cout<<b[l]<<" "<<b[r]<<" ";
            l++;
            r--;       
        }
        if(l==r) cout<<b[l]<<"\n";
        else cout<<"\n";
    }
}