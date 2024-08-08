#include<bits/stdc++.h>
# define mod (long long) 1000000007
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
long long inv (long long t) //debugged
{
    long long p = (long long) mod -2;
    long long ans=1;
    t=t%mod;
    while(p)
    {
        if(p&1) ans = (ans*t)%mod;
        p>>=1;
        t=(t*t)%mod;
    }
    return ans%mod;
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
        res=(res*m)%mod;
        res=(res*inv(d))%mod;
    }
    return res;
}
long long solve(int n, int k, int cnt)
{
    long long N = (long long) n;
    long long K = (long long) k;
    long long CNT = (long long) cnt;
    long long ans=0;
    long long lower =max(K+CNT-N,(long long) 0);
    long long upper =min(CNT,(K-1)/2);
    long long nCr1=nCr(CNT,lower)%mod;
    long long nCr2=nCr(N-CNT,K-lower)%mod;
    for(long long i=lower; i<= upper; i++)
    {
        ans=(ans+(nCr1*nCr2)%mod)%mod;
        nCr1=(nCr1*(CNT-i))%mod;
        nCr1=(nCr1*inv(i+1))%mod;
        nCr2=(nCr2*(K-i))%mod;
        nCr2=(nCr2*inv(N-CNT+i-K+1))%mod;
    }
    return ans%mod;
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