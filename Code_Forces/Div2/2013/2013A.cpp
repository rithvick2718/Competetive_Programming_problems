#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //test cases
    cin>>t;
    int n,x,y;
    while(t--)
    {
        //code
        cin>>n>>x>>y;
        if(y>x)
        {
            if(n%x==0) cout<<n/x<<"\n";
            else cout<<(n/x)+1<<"\n";
        }
        else
        {
            if(n%y==0) cout<<n/y<<"\n";
            else cout<<(n/y)+1<<"\n";
        }
    }
}