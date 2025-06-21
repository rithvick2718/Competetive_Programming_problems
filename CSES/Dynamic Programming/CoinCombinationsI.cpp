#include<iostream>
#include<vector>
using namespace std;
#define MOD 1'000'000'007
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    vector<int> ways(x+1,0);
    ways[0]=1;
    for(int i=1; i<x+1 ; i++){
        for(int j=0; j<n; j++){
            if(i-coins[j]>=0) ways[i]=(ways[i]+ways[i-coins[j]])%MOD;
        }
    }
    cout<<ways[x];
}