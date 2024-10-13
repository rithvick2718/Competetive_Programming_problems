#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    long long n;
    cin>>n;
    long long p[n+1];
    p[0]=0;
    long long sum=0;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
        sum+=p[i];
    }
    sort(p,p+n+1);
    long long mn=LONG_LONG_MAX;
    for(long long i=1; i<=n; i++)
    {
        mn=min((2*i-n-2)*p[i]-2*p[i-1]+sum,mn);
        p[i]+=p[i-1];
    }
    cout<<mn;
}