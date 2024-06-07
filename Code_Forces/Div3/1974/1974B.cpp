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
        cin>>n;
        string s,r;
        char y;
        for (size_t i = 0; i < n; i++)
        {
            cin>>y;
            s.push_back(y);
        }
        
        r=s;
        sort(r.begin(),r.end());
        auto unique_end = std::unique(r.begin(), r.end());
        r.erase(unique_end, r.end());
        map<char,char> k;
        int z =(int) r.size();
        for (size_t i = 0; i < z; i++)
        {
            k[(char)r[i]]=(char)r[z-1-i];
        }
        z=(int)s.size();
        for(int i =0; i< z; i++)
        {
            s[i]=k[s[i]];
        }
        cout<<s<<"\n";
    }
}