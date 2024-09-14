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
        cin>>n>>m>>q;
        int b[m];
        for(int i=0; i<m; i++)
        {
            cin>>b[i];
        }
        sort(b,b+m); 
        int d;
        int point;
        for(int i=0 ; i<q ; i++) //queries
        {
            //b is sorted
            cin>>d; //I think in harder problem we will use binary search
            if(d<b[0]) cout<<b[0]-1<<"\n";
            else if(d>b[m-1]) cout<<n-b[m-1]<<"\n";
            else
            {
                point = lower_bound(b,b+m,d)-b; // so I think b[point]>=d but b[point-1]<d
                cout<<(b[point]-b[point-1])/2<<"\n";
            }
        }
    }
}