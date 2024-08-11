#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,m,k;
    while(t--)
    {
        //code
        cin>>n>>m>>k;
        cout<<(min(n,k))*(min(m,k))<<"\n";
    }
}