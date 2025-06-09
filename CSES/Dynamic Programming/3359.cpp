#include<bits/stdc++.h>
using namespace std;
int main()
{
    // ifstream cin;
    // ofstream cout;
    // cin.open("D:\\Work\\Competetive_Programming_problems\\test_input.txt");
    // cout.open("D:\\Work\\Competetive_Programming_problems\\output.txt");
    int n;
    cin>>n;
    string l;
    vector<string> dp(n,"");
    cin>>l;
    dp[0]+=l[0];
    for(int i=1; i<n; i++){
        dp[i]=dp[i-1]+l[i];
    }
    for(int i=1; i<n; i++){
        cin>>l;
        dp[0]+=l[0];
        for(int j=1; j<n; j++){
            if(dp[j-1]<dp[j]) dp[j]=dp[j-1];
            dp[j]+=l[j];
        }
    }
    cout<<dp[n-1];
}