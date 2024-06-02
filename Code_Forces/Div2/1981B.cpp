#include<bits/stdc++.h>
using namespace std;
 int initialans( int n) {
     int m = 1;
    while (n != 0) {
        n >>= 1; // Right shift n by 1
        m <<= 1; // Left shift m by 1
    }
    return (max(0,(m >> 1)-1)); // Right shift m by 1 to get the final result
}
 int bitcal ( int n,  int m)
{
     int init = max(( int)0,max(initialans(n),n-m));
     int ans = init;
    for( int i= init; i<=n+m; i++)
    {
        ans = ans|i;
    }
    return(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
     int n;
     int m;
    while(t--)
    {
        //write the code for each test case here
        cin>>n>>m;
        cout<<bitcal(n,m)<<"\n";
    }
}