#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // bool a[8][8]={};
    vector<pair<int,int>> p;
    char c;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cin>>c;
            if(c=='*') p.push_back({i+1,j+1});
        }
    }
    for(auto x : p)
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }
}