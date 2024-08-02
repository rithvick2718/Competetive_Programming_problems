#include<bits/stdc++.h>
using namespace std;
int teams(const vector<int> &v,int s)
{
    //we sort the vector before in hand
    int teams=0;
    int l=0; 
    int r=(int)v.size()-1;
    while(l<r)
    {
        if(v[l]+v[r]>s) r--;
        else if(v[l]+v[r]<s) l++;
        else
        {
            teams++;
            l++;
            r--;
        }
    }
    return teams;
}//This is O(n). This is fast, now we need a fast way to get all possible s.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> w(n);
        for (size_t i = 0; i < n; i++)
        {
            cin>>w[i];
        }
        sort(w.begin(),w.end()); //O(n*log n) here the trouble begins
        set<int> s;
        for(int i=0; i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                s.insert(w[i]+w[j]);
            }
        }
        int mx=0;
        for(auto x: s)
        {
            mx=max(teams(w,x),mx);
        }
        cout<<mx<<"\n";
    }
}