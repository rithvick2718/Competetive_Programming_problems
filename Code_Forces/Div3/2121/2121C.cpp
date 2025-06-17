#include<bits/stdc++.h>
using namespace std;
bool count_out_non_align_pairs(const vector<pair<int,int>> &M, int r, int c){
    for(auto m : M){
        if(r!=m.first && c!=m.second) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m,in;
        cin>>n>>m;
        int mx = 0;
        vector<pair<int,int>> mx_pos;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>in;
                if(in>mx){
                    mx_pos.clear();
                    mx_pos.push_back({i,j});
                    mx=in;
                }
                else if(mx==in) mx_pos.push_back({i,j});
            }
        }
        if(mx_pos.size()<=2) cout<<mx-1<<"\n";
        else{
            pair<int,int> P1= mx_pos[0];
            pair<int,int> P2= {-1,-1};
            for(int i=1; i<mx_pos.size();i++){
                if(mx_pos[i].first !=P1.first && mx_pos[i].second !=P1.second){
                    P2=mx_pos[i];
                    break;
                }
            }
            if(P2.first==-1) cout<<mx-1<<"\n";
            else{
                vector<int> R ={P1.first,P2.first};
                vector<int> C ={P1.second,P2.second};
                bool ans = false;
                for(auto r : R){
                    for(auto c : C){
                        ans = ans | count_out_non_align_pairs(mx_pos,r,c);
                        if(ans) break;
                    }
                }
                if(ans) cout<<mx-1<<"\n";
                else cout<<mx<<"\n";
            }
        }
    }
}