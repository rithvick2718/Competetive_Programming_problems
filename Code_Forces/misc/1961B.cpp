#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    int r =a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return(b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;//test cases
    cin>>t;
    int a,b,g;
    while(t--)
    {
        cin>>a>>b; //we know a<b
        if(b%a==0) cout<<b*(b/a)<<"\n";
        else
        {
            int g = gcd(a,b);
            cout<<a*(b/g)<<"\n";
        }
    }
}