#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long x[n];
    for(int i=0; i<n;i++)
    {
        cin>>x[i];
    }
    long long mx=x[0];
    long long ans=0;
    for(int i=0; i<n;i++)
    {
        mx =max(mx,x[i]);
        ans+=(mx-x[i]);
    }
    cout<<ans;
}