#include<iostream>
#include<vector>
#define MOD 1'000'000'007
using namespace std;
// void print_v (const vector<vector<int>> &DP){
//     int n = DP.size();
//     for(int i=0; i<n; i++){
//         cout<<i<<" : ";
//         for(auto dp : DP[i]) cout<<dp<<" ";
//         cout<<"\n";
//     }
// }
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        for(int j=1; j<=6 && i-j>=0; j++){
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    cout<<dp[n];
}