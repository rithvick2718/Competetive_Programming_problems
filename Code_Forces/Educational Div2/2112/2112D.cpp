#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> depth;
void bfs_special(int root,bool dir)
{
    for(auto child : tree[root]){
        if(depth[child]==-1){
            depth[child] = 1+depth[root];
            if(dir) cout<<root<<" "<<child<<"\n";
            else cout<<child<<" "<<root<<"\n";
        }
    }
    for(auto child : tree[root]){
        if(depth[child]==1+depth[root]) bfs_special(child,!dir);
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
        int n;
        cin>>n;
        tree.assign(n+1,{});
        depth.assign(n+1,-1);
        int u,v;
        for(int i=1; i<n; i++){
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int i=1;
        bool present = false;
        for(;i<=n;i++) {
            if(tree[i].size()==2){
                present = true;
                break;
            }
        }
        if(present){
            cout<<"YES\n";
            depth[i]=0;
            depth[tree[i][0]]=1;
            depth[tree[i][1]]=1;
            cout<<i<<" "<<tree[i][0]<<"\n";
            cout<<tree[i][1]<<" "<<i<<"\n";
            bfs_special(tree[i][0],false);
            bfs_special(tree[i][1],true);
        }
        else
            cout<<"NO\n";
    }
}