#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // this activity scheduling problem
    map<int,int> mp;
    int start,end;
    for(int i=0; i<n; i++)
    {
        cin>>start>>end;
        mp[end]=max(start,mp[end]);
    }
    int ans=0;
    auto current_activity=mp.begin();
    auto last_activity=current_activity;
    current_activity++;
    ans++;
    while(current_activity!=mp.end())
    {
        if((*last_activity).first<=(*current_activity).second){
            ans++;
            last_activity=current_activity;
        }
        current_activity++;
    }
    cout<<ans;
}