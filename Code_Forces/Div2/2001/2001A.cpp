#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    int n;
    while(t--)
    {
        //code
        cin>>n;
        map<int,int> m;
        int a;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            if(m.find(a)==m.end()) m[a]=1;
            else m[a]++;
        }
        int max=-1;
        for(auto x : m)
        {
            if(x.second > max) max=x.second;
        }
        cout<<n-max<<"\n";
    }
}