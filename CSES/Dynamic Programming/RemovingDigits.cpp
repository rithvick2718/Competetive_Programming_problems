#include<bits/stdc++.h>
using namespace std;
vector<int> digits(int n)
{
    vector<int> digits;
    vector<bool> present(10,false);
    while(n>0){
        present[n%10]=true;
        n/=10;
    }
    for(int i=1; i<=9; i++){
        if(present[i]) digits.push_back(i);
    }
    return digits;
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, 1e7);
    dp[0]=0;
    vector<int> dts;
    for(int i=1; i<=n; i++){
        dts= digits(i);
        for(auto dt : dts){
            dp[i]=min(dp[i],1+dp[i-dt]);
        }
    }
    cout<<dp[n];
}