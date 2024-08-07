#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(2*a-b>=0 && (2*a-b)%3==0 ) cout<<"YES\n";
        else cout<<"NO\n";
    }
}