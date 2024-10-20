#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code
        int a,b;
        cin>>a>>b;
        if(a>=b) cout<<a<<"\n";
        else
        {
            int x=b-a;
            if(a-x>0) cout<<a-x<<"\n";
            else cout<<0<<"\n";
        }
    }
}