#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<vector<int>> grid(n, vector<int>(n,-1));
        int i=(n-1)/2,j=i;
        vector<pair<int,int>> move = {{0,1},{1,0},{0,-1},{-1,0}};
        int assign =0;
        grid[i][j]=assign;
        assign++;
        int move_pointer=0;
        for(int strip=1; strip<n; strip++){
            i+=move[move_pointer].first;
            j+=move[move_pointer].second;
            grid[i][j]=assign;
            assign++;
            move_pointer++;
            move_pointer%=4;
            for (int rep = 0; rep <strip; rep++)
            {
                i+=move[move_pointer].first;
                j+=move[move_pointer].second;
                grid[i][j]=assign;
                assign++;
            }
            move_pointer++;
            move_pointer%=4;
            for (int rep = 0; rep <strip; rep++)
            {
                i+=move[move_pointer].first;
                j+=move[move_pointer].second;
                grid[i][j]=assign;
                assign++;
            }
        }
        for(auto gri : grid){
            for(auto gr : gri) cout<<gr<<" ";
            cout<<"\n";
        }
    }
}