#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> dict;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    dict['A']=0;
    dict['B']=1;
    dict['C']=2;
    dict['D']=3;
    while(t--)
    {
        //code
        int n;
        cin>>n;
        string t;
        cin>>t;
        vector<int> vals(4,0); 
        for(int i=0; i<4*n;i++)
        {
            if(t[i]!='?') vals[dict[t[i]]]++;
        }
        int ans=0;
        for(auto k : vals)
        {
            if(k>n) ans+=n;
            else ans+=k;
        }
        cout<<ans<<"\n";
    }
}