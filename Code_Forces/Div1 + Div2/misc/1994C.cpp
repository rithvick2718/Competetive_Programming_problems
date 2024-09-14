#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    long long x;
    while(t--)
    {
        cin>>n>>x;
        long long a[n];
        long long ans=0;
        long long g;
        for(int i=0; i<n; i++)
        {
            cin>>a[i]; 
        }
        for(int i=0 ; i <n ; i++)
        {
            g=0;
            for(int j=i; j<n; j++)
            {
                g+=a[j];
                if(g<=x) ans++;
                else g=0;
            }
        }
        cout<<ans<<"\n";
    }
}