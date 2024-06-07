#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int f,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>f>>k;
        vector<int> a(n);
        for(int i =0; i<n; i++)
        {
            cin>>a[i];
        }//got the array
        int  spl =a[f-1];
        sort(a.begin(),a.end()); //sort it
        auto l =lower_bound(a.begin(),a.end(),spl);
        auto h =upper_bound(a.begin(),a.end(),spl);
        int lp = distance(a.begin(),l);
        int hp = distance(a.begin(),h)-1;
        if(hp<n-k) cout<<"NO\n";
        else if(lp>=n-k) cout<<"YES\n";
        else cout<<"MAYBE\n";
    }
}