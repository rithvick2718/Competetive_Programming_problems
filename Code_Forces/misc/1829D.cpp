#include<bits/stdc++.h>
using namespace std;
int findpower(int &n, int p) //fine 
{
    int ans=0;
    while(n%p==0)
    {
        ans++;
        n/=p;
    }
    return(ans);
} //fine by me
bool solve(int &n, int &m)
{
    if(m==n) return true;
    if(m>n) return false;
    //now we know m<n
    int m2=findpower(m,2);
    int m3=findpower(m,3);
    int n2=findpower(n,2);
    int n3=findpower(n,3);
    if(m2>=n2 && m3<=n3 && m2-n2<=n3-m3 && m==n) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        if(solve(n,m)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}