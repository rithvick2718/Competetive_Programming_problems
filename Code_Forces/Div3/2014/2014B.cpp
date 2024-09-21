#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    int n,k;
    while(t--)
    {
        //code
        cin>>n>>k;
        if(k&1) // k is odd
        {
            if(n&1)
            {
                if(((k-1)>>1)&1) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else
            {
                if(((k-1)>>1)&1) cout<<"NO\n";
                else cout<<"YES\n";
            }
        }
        else // k is even
        {
            if((k>>1)&1) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}