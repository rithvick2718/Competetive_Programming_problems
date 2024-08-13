#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while (t--)
    {
        cin>>n;
        long long presum[n+1];
        presum[0]=(long long)0;
        long long h;
        for(int i=1; i<=n; i++)
        {
            cin>>h;
            presum[i]=presum[i-1]+h;
        } //getting presum array
        int low=0;
        int high=n-1;
        long long ans=0;
        string p;
        cin>>p;
        while(low<high)
        {
            if(p[low]=='L' && p[high]=='R')
            {
                ans+=presum[high+1]-presum[low];
                low++;
                high--;
            }
            else if(p[low]=='L') high--;
            else if(p[high]=='R') low++;
            else
            {
                low++;
                high--;
            }
        }
        cout<<ans<<"\n";
    }
}