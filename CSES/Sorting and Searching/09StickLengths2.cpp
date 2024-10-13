#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long p[n];
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    nth_element(p,p+(n/2),p+n);
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=abs(p[i]-p[(n/2)]);
    }
    cout<<ans;
}