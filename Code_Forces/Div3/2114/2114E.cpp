#include<bits/stdc++.h>
using namespace std;
#define ll long long
void BFS(const vector<ll> &dangers,const vector<vector<ll>> &adjacents, vector<ll> &threats,vector<bool> &done,ll mx_sum=0,ll mn_sum=0, ll t_sum=0LL,int bfs_on=1, ll t_multiply = 1LL)
{
    done[bfs_on]=true;
    t_sum+=t_multiply*dangers[bfs_on];
    if(t_multiply==1) threats[bfs_on]=t_sum-mn_sum;
    else threats[bfs_on]=-t_sum+mx_sum;
    mn_sum=min(t_sum,mn_sum);
    mx_sum=max(t_sum,mx_sum);
    if(adjacents[bfs_on].empty()) return;
    for(auto adjacent : adjacents[bfs_on]){
        if(!done[adjacent]) BFS(dangers,adjacents,threats,done,mx_sum,mn_sum,t_sum,adjacent,-t_multiply);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        //code
        int n;
        cin>>n;
        vector<ll> dangers(n+1); // ignore 0  in this
        for(int i=1; i<=n; i++) cin>>dangers[i];
        vector<vector<ll>> adjacents(n+1);
        ll u,v;
        for(int i=0; i<n-1; i++){
            cin>>u>>v;
            adjacents[u].push_back(v);
            adjacents[v].push_back(u);
        }
        vector<ll> threats(n+1);
        vector<bool> done(n+1,false);
        BFS(dangers,adjacents,threats,done);
        for(int i=1; i<=n; i++) cout<<threats[i]<<" ";
        cout<<"\n";
    }
}