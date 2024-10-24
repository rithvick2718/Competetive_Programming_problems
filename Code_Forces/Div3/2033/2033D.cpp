#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n;
    cin>>tt;
    while(tt--)
    {
        //code
        cin>>n;
        int presum[n+1];
        presum[0]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>presum[i];
            presum[i]+=presum[i-1];
        }
        set<int> s;
        s.insert(presum[0]);
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(s.count(presum[i])>0){
                ans++;
                s.clear();
                s.insert(presum[i]);
            }
            else s.insert(presum[i]);
        }
        cout<<ans<<"\n";
    }
}