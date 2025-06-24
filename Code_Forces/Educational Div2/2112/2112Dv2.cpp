#include<bits/stdc++.h>
using namespace std;
#define MAXN 2'00'001
vector<int> tree[MAXN];
bool visited[MAXN];
void dfs_special(int root,bool dir)
{
    for(auto child : tree[root]){
        if(!visited[child]){
            visited[child]=true;
            if(dir) cout<<root<<" "<<child<<"\n";
            else cout<<child<<" "<<root<<"\n";
            dfs_special(child,!dir);
        }
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
        for(int i=0; i<=n; i++){
            tree[i].clear();
            visited[i]=false;
        }
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
            visited[i]=true;
            visited[tree[i][0]]=true;
            visited[tree[i][1]]=true;
            cout<<i<<" "<<tree[i][0]<<"\n";
            cout<<tree[i][1]<<" "<<i<<"\n";
            dfs_special(tree[i][0],false);
            dfs_special(tree[i][1],true);
        }
        else
            cout<<"NO\n";
    }
}