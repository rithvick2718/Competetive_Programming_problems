#include<iostream>
using namespace std;
void convert (bool a[],int n, int k)
{
    int i=0;
    while (k)
    {
        a[i]=(k&1)^((k>>1)&1);
        k>>=1;
        i++;
    }
}
void print(bool a[], int n)
{
    for(int i=n-1; i>=0;i--)
    {
        if(a[i]) cout<<1;
        else cout<<0;
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool a[n]={};
    for(int i=0; i<(1<<(n));i++)
    {
        print(a,n);
        convert(a,n,i+1);
    }
}