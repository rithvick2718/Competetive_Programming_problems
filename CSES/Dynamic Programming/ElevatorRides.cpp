#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x,k;
    cin>>n>>x;
    const int PN=1<<n;
    int w[n];
    for(int i=0; i<n; i++) cin>>w[i];
    vector<pair<int,int>> dp(PN);
    pair<int,int> temp;
    dp[0]={1,0};
    for(int i=1; i<PN; i++){
        dp[i]={n+1,0};
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                k=i^(1<<j);
                temp = dp[k];
                if(temp.second+w[j]<=x){
                    temp.second+=w[j];
                }
                else{
                    temp.first++;
                    temp.second=w[j];
                }
                dp[i]=min(temp,dp[i]);
            }
        }
    }
    cout<<dp[PN-1].first;
}