#include<bits/stdc++.h>
using namespace std;
long long int firstfact(long long int n)
{
    if(n==1) return(1);
    long long int i=2;
    if(n%i==0) return(i);
    i=3;
    while(n%i!=0)
    {
        i=i+2;
    }
    return(i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long int x,y,z;
        long long int k;
        cin>>x>>y>>z;
        cin>>k;
        if(k>x*y*z) cout<<0<<"\n";
        else
        {
            cout<<1<<"\n";
        }
    }
}