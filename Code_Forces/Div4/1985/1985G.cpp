#include<bits/stdc++.h>
using namespace std;
long long int ten(long long int n)
{
    long long int ans =1;
    int m =n;
}
long long int df(long long int n)
{
    int ans=0;
    while(n)
    {
        ans=ans+(n%10);
        n=n/10;
    }
    return(ans);
}
bool okay (long long int n, long long int k)
{
    long long int a= df(k*n);
    long long int b=df(n);
    if(a==k*b) return(true);
    return(false);
}
long long int solve(long long int l, long long int r, long long int k)
{
    int ans=0;
}
int main()
{

}