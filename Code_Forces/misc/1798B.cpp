#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int m;
    while(t--)
    {
        cin>>m;
        int size;
        int help;
        vector<vector<int>> a(m);
        for(int i=0; i<m;i++)
        {
            cin>>size;
            while(size>0)
            {
                cin>>help;
                a[i].push_back(help);
                size--;
            }
        }//getitng a's
        
    }
}