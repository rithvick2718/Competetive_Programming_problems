#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long mn =0; 
        long long mx =0;
        long long prev=0;
        long long h;
        while(n--)
        {
            cin>>h;
            mx=max(abs(mx+h),abs(mn+h));
            mn+=h;
        }
        cout<<mx<<"\n";
    }
}