#include<bits/stdc++.h>
using namespace std; 
long long int f(long long int n, long long int a, long long int b, long long int k)
{
    return(((b-a)*k)+(a*n)+((k*(1-k))/2));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    while(t--)
    {
        //code for each test case
        long long int n,a,b;
        cin>>n>>a>>b;
        if(b-a>=0)
        {
            long long int k=min(b-a,n-1);
            long long int m = max(f(n,a,b,k),f(n,a,b,k+1));
            m = max(m,a*n);
            cout<<m<<"\n";
        }
        else
        {
            cout<<a*n<<"\n";
        }
    }
}