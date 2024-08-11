#include<bits/stdc++.h>
using namespace std;
bool checkD(pair<long long,long long> point, pair<long long,long long> start , pair<long long,long long> end)
{
    long long h=(point.first-start.first)*(point.first+start.first-2*end.first)+(point.second-start.second)*(point.second+start.second-2*end.second);
    return(h>0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        //code
        cin>>n;
        pair<long long,long long> start;
        pair<long long,long long> end;
        vector<pair<long long,long long>> centers(n);
        for(int i=0; i<n; i++)
        {
            cin>>centers[i].first>>centers[i].second;
        }
        cin>>start.first>>start.second>>end.first>>end.second;
        bool ans=true;
        for(int i=0; i<n && ans ; i++)
        {
            ans=checkD(centers[i],start,end);
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}