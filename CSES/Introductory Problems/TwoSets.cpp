#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n%4==0)
    {
        cout<<"YES\n";
        cout<<n/2<<"\n";
        int i=1;
        for(; i<=n/4; i++)
        {
            cout<<i<<" ";
        }
        i=n/4-1;
        for(;i>=0;i--)
        {
            cout<<n-i<<" ";
        }
        cout<<"\n"<<n/2<<"\n";
        i=n/4 +1;
        for(;i<=3*(n/4);i++)
        {
            cout<<i<<" ";
        }
    }
    else if(n%4==3)
    {
        cout<<"YES\n";
        cout<<n/2+1<<"\n";
        cout<<1<<" "<<2<<" ";
        for(int i=1; 4*i+3<=n;i++)
        {
            cout<<4*i<<" "<<4*i+3<<" ";
        }
        cout<<"\n"<<n/2<<"\n";
        cout<<3<<" ";
        for(int i=1;4*i+3<=n;i++)
        {
            cout<<4*i+1<<" "<<4*i+2<<" ";
        }
    }
    else cout<<"NO"; //here it means that n%4 == 1 || n%4==2
}