#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        //code
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end()); //fine
        priority_queue<int> diff;
        for(int i=n-1; i>=1; i-=2)
        {
            diff.push(a[i]-a[i-1]);
        }
        int to_dec;
        while(k>0 && !(diff.empty()))
        {
            to_dec=min(k,diff.top());
            k-=to_dec;
            if(k==0)
            {
                int h=diff.top()-to_dec;
                diff.pop();
                diff.push(h);
            }
            else diff.pop();
        }
        int ans=0;
        while(!(diff.empty()))
        {
            ans+=diff.top();
            diff.pop();
        }
        if(n&1) ans+=a[0];
        cout<<ans<<"\n";
    }
}