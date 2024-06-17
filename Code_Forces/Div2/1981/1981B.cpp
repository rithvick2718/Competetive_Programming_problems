#include<bits/stdc++.h>
using namespace std;
int countBits(int n) //1-index
{
    int ans=0;
    while (n)
    {
        ans++;
        n>>=1;
    }
    return(ans);
}
int solve(const int &n, const int &m)
{
    if(m==0) return(n);
    int a = n^(n+m);
    int b = n^(max(0,n-m));
    int c =max(countBits(a),countBits(b));
    return(n|((1<<c)-1));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
     int n;
     int m;
    while(t--)
    {
        //write the code for each test case here
        cin>>n>>m;
        cout<<solve(n,m)<<"\n";
    }
}