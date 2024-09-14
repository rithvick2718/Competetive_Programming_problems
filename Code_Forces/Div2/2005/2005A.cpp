#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    map<int, char> g;
    g[0]='a';
    g[1]='e';
    g[2]='i';
    g[3]='o';
    g[4]='u';
    int n;
    while(t--)
    {
        //code
        cin>>n;
        vector<int> toprint(5,n/5);
        for(int i=0; i<n%5; i++)
        {
            toprint[i]++;
        }
        for(int i=0; i<5;i++)
        {
            for(int j=0; j<toprint[i];j++)
            {
                cout<<g[i];
            }
        }
        cout<<"\n";
    }
}