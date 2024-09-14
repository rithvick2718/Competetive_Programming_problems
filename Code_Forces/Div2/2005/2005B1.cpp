#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,m,q;
    while(t--)
    {
        //code
        cin>>n>>m>>q; //m=2, q=1
        int b[m];
        for(int i=0; i<m; i++)
        {
            cin>>b[i];
        }
        int d;
        for(int i=0 ; i<q ; i++) //queries
        {
            cin>>d; //I think in harder problem we will use binary search
            if(d<=b[0] && d<=b[1])
            {
                cout<<min(b[0],b[1])-1<<"\n";
            }
            else if(d>=b[0] && d>=b[1])
            {
                cout<<n-max(b[0],b[1])<<"\n";
            }
            else cout<<(abs(b[1]-b[0]))/2<<"\n";
        }
    }
}