#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    long long val=(n*(n+1))/2;
    long long in;
    for(int i=0; i< (int) n-1;i++)
    {
        cin>>in;
        val-=in;
    }
    cout<<val;
}