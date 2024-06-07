#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    int m;
    while (t--)
    {
        cin>>n>>m;
        if(m>n) cout<<"NO \n";
        else
        {
            if((n-m)%2==0) cout<<"YES \n";
            else cout<<"NO \n";
        }
    }
}