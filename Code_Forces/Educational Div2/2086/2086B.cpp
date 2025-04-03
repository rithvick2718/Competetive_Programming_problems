#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code
        long long n,k,x;
        cin>>n>>k>>x;
        vector<long long> pre_sum(n);
        cin>>pre_sum[0];
        for (int i = 1; i < n; i++)
        {
            cin>>pre_sum[i];
            pre_sum[i]+=pre_sum[i-1];
        }
        if(x>pre_sum[n-1]*k) cout<<0<<"\n";
        else{
            long long r=x%pre_sum[n-1];
            long long q=x/pre_sum[n-1];
            long long to_add= (long long)distance(pre_sum.begin(),lower_bound(pre_sum.begin(),pre_sum.end(),pre_sum[n-1]-r+1))+1LL;
            if(r==0){
                cout<<n*(k-q)+1<<"\n";
            }
            else cout<<n*(k-q-1)+to_add<<"\n";
        }
    }
}