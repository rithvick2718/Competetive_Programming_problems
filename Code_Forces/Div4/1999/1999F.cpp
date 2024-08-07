#include<bits/stdc++.h>
# define mod 1000000007
using namespace std;
long long gcd(long long a, long long b)//fine
{
    if(a==0) return b;
    if(b==0) return a;
    long long r = a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
long long nCr(long long n, long long r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    // Since C(n, r) = C(n, n-r)
    if (r > n - r) r = n - r;

    long long res = 1;
    long long m,d,g;
    for (long long i = 0; i < r; i++) {
        m=n-i;
        d=i+1;
        g=gcd(m,d);
        m/=g;
        d/=g;
        res/=d;
        res*=m;
    }
    return res;
}
long long solve(int n, int k, int cnt)
{
    long long N = (long long) n;
    long long K = (long long) k;
    long long CNT = (long long) cnt;
    long long ans=0;
    for(long long i=max(K+CNT-N,(long long) 0); i<= min(CNT,(K-1)/2) ; i++)
    {
        ans=(ans+((nCr(CNT,i)%mod)*(nCr(N-CNT,K-i)%mod))%mod);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        cin>>n>>k;
        int cnt=0;
        bool h;
        for(int i=0; i<n; i++)
        {
            cin>>h;
            if(!h) cnt++;
        }
        cout<<solve(n,k,cnt)<<"\n";
    }
}