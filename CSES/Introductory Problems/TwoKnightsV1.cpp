#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    long long t[] ={0,6,28,96,252,550,1056,1848}; // so these are the first 8 values
    if(n<=8)
    {
        for(long long i=0; i<n;i++)
        {
            cout<<t[i]<<"\n";
        }
    }
    else
    {
        for(long long i=0; i<8;i++)
        {
            cout<<t[i]<<"\n";
        }
        long long l1=t[7];
        long long l2=t[6];
        long long h;
        for(long long k=9;k<=n;k++)
        {
            h=l2+4*k*k*k-12*k*k-2*k+34;
            cout<<h<<"\n";
            l2=l1;
            l1=h;
        }
    }
}