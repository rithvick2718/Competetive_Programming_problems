#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        int a[n][n]; //taking G
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        int p[2*n]; // this is permutation
        vector<bool> there (2*n,false); // know which element is not there i.e. p[0]
        for(int i=1; i<=n; i++) //p[1] = a[0][0], p[2]=a[0][1] ...
        {
            p[i]=a[0][i-1];
        }
        for(int i=1; i<=n; i++) //
        {
            p[i+n]=a[n-1][i];
        }
        for(int i=1; i<2*n; i++)
        {
            there[p[i]-1]=true;
        }
        for(int i=0; i<2*n; i++)
        {
            if(!there[i]) {
                p[0]=i+1;
                break;
            }
        }
        for(int i=0; i<2*n; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<"\n";
    }
}