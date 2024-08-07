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
        long long last =t[7];
        for(long long k=9;k<=n;k++)
        {
            last+=(2*k-1)*(k-1)*(k)-8*k+16;
            cout<<last<<"\n";
        }
    }
}