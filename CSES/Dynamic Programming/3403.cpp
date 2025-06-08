#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(a[i-1]==b[j-1]) {
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    int i=n,j=m;
    deque<int> q;
    while(i>=1 && j>=1){
        if(a[i-1]==b[j-1]){
            q.push_front(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>=dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    for(auto a : q) cout<<a<<" ";
} 