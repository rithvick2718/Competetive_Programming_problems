#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<int,long long> mp;
    int a,b;
    for(int i=0; i<n;i++)
    {
        cin>>a>>b;
        mp[a]++;
        mp[b]--;
    }
    int tot=0;
    int mx=INT_MIN;
    for(auto x : mp)
    {
        tot+=x.second;
        if(tot>mx) mx=tot;
    }
    cout<<mx;
}