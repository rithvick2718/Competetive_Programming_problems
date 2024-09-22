#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    int quer=1;
    int n,m,h;
    while(t--)
    {
        //code
        cin>>n>>m>>h;
        vector<vector<int>> adjmat(n,vector<int>(n,INT_MAX)); // the idea is that like in graph we make the adj matrix
        // adjmat[a][b] means a edge from a to b and it's weight
        bool hashorse[n]={};
        int invar;
        for(int i=0; i<h; i++)
        {
            cin>>invar;
            hashorse[invar-1]=true;
        }
        int u,v,w;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>w;
            adjmat[u-1][v-1]=w;
            adjmat[v-1][u-1]=w;
        } //took input
        cout<<"Graph "<<quer<<" taken\n";
        quer++;
    }
}