#include<bits/stdc++.h>
using namespace std;
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
        int a[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cin>>a[i][j];
        }
        vector<int> S;
        int bait=0;
        for(int i=0; i<n; i++){
            int o=0;
            for(int j=n-1;j>=0; j--)
            {
                if(a[i][j]==1) o++;
                else break;
            }
            if(o!=0) S.push_back(o);
            else bait++;
        }
        sort(S.begin(),S.end());
        int MEX;
        if(bait!=0) MEX=1;
        else MEX=0;
        for(auto s :S){
            if(MEX<=s) MEX++;
        }
        cout<<MEX<<"\n";
    }
}