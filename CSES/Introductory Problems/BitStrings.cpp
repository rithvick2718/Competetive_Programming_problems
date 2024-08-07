#include<iostream>
#define mod 1000000007
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=1;
    while(n--)
    {
        ans<<=1;
        ans%=mod;
    }
    cout<<ans;
}