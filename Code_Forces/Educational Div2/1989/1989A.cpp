#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int x,y;
    int c=0;
    for(int i =0; i<n; i++)
    {
        cin>>x>>y;
        if(y>-2) cout<<"YES\n";
        else cout<<"NO\n"; 
    }
}