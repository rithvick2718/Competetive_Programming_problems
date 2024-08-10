#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        //code
        cin>>n;
        int p[n];
        for(int i=0; i<n; i++)
        {
            cin>>p[i];
        }
        for(int i=1; i<n;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<p[0]<<"\n";
    }
}