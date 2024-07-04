#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a==0 || b ==0) return -1;
    int r =a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return(b);
}
int lcm(int a, int b)
{
    return(a*(b/gcd(a,b)));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int l=n-1;
        int ans=1;
        int k=n-1;
        for(int i=2; i*i<=n;i++)
        {
            if(n%i==0)
            {
                k=lcm(i,n-i);
                if(k<l) {
                    ans =i;
                    l=k;
                }
                k=lcm(n/i,n-(n/i));
                if(k<l) {
                    ans =n/i;
                    l=k;
                }
            }
        }
        cout<<ans<<" "<<n-ans<<"\n";
    }
}