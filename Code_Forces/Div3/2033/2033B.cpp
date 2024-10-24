#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n;
    cin>>tt;
    while(tt--)
    {
        //code
        cin>>n;
        int in;
        vector<int> mn(2*n-1,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
               cin>>in;
               mn[i-j+n-1]=min(in,mn[i-j+n-1]); 
            }
        }
        int sum=0;
        for(auto x :mn) sum-=x;
        cout<<sum<<"\n";
    }
}