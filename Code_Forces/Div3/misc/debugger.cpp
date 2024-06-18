#include<bits/stdc++.h>
using namespace std;
int maxPower(int &m, const int &n) //the power of n in m
{
    int ans =0;
    while (m%n==0)
    {
        ans++;
        m=m/n;
    }
    return(ans);
}
int itrpow(int a, int n) //a^n (mathmatically)
{
    int tomultiply = a;
    int ans =1;
    while(n)
    {
        if(n&1) ans = ans*tomultiply;
        tomultiply=tomultiply*tomultiply;
        n>>=1;
    }
    return(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n, m;
    while(t--)
    {
        cin>>n;
        cin>>m;
        //cout<<"The max power of "<<n<<" in "<<m<<" is "<<maxPower(m,n)<<" remainder is "<<m<<"\n";
        cout<<n<<"^"<<m<<"="<<itrpow(n,m)<<"\n";
    }
}