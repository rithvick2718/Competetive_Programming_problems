#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while (t--)
    {
        long long n,m,k;
        cin>>n>>m>>k;
        long long w;
        cin>>w;
        vector<long long> g(w);
        for(long long i=0; i<w; i++)
        {
            cin>>g[i];
        }
        int q[n*m];
        int ind=0;
        long long l,r;
        for(long long i=1; i<=n; i++)
        {
            for(long long j=1; j<=m; j++)
            {
                l=min({i,n-i+1,k,n-k+1});
                r=min({j,m-j+1,k,m-k+1});
                q[ind]=l*r;
                ind++;
            }
        }
        ind--;
        sort(q,q+n*m);
        long long ans=0;
        sort(g.rbegin(),g.rend());
        for(int i=0; i<w; i++)
        {
            ans+=g[i]*q[ind];
            ind--;
        }
        cout<<ans<<"\n";
    }
}