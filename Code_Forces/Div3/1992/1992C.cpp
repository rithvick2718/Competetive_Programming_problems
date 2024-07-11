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
        cin>>n>>m>>k;
        while (n)
        {
            if(n>m) cout<<n<<" ";
            else break;
            n--;
        }
        for(int i=1; i<=m ; i++)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}