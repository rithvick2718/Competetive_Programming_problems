#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int z;
    cin>>z;
    string s,t;
    while(z--)
    {
        cin>>s>>t;
        if(s[0]!=t[0]) cout<<s.length()+t.length()<<"\n";
        else
        {
            int common=0;
            int p = min(s.length(),t.length());
            for ( ; common < p; common++)
            {
                if(s[common]!=t[common]) break;
            }
            cout<<s.length()+t.length()-common+1<<"\n";
        }
    }
}