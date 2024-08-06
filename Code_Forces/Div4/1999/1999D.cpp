#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    string t,s;
    while(test--)
    {
        //code
        cin>>s;
        cin>>t;
        int q=0;
        for(char p : s)
        {
            if(p=='?') q++;
        }
        bool cansolve=false;
        if(q>=t.length())
        {
            cansolve=true;
            int j=0;
            for(char &p : s)
            {
                if(p=='?')
                {
                    if(j<t.length())
                    {
                        p=t[j];
                        j++;
                    }
                    else
                    p='a'+rand()%26;
                }
            }
        }
        else
        {
            int t_it=0;
            int s_it=0;
            while(t_it<t.length() && s_it<s.length())
            {
                if(t[t_it]==s[s_it])
                {
                    t_it++;
                    s_it++;
                    if(t_it==t.length()) cansolve=true;
                }
                else
                {
                    if(s[s_it]=='?')
                    {
                        s[s_it]=t[t_it];
                        t_it++;
                        s_it++;
                        if(t_it==t.length()) cansolve=true;
                    }
                    else s_it++;
                }
            }
            if(cansolve)
            {
                for(char &p : s)
                {
                    if(p=='?')
                    {
                        p='a'+rand()%26;
                    }
                }
            }
        }
        if(cansolve) {
            cout<<"YES\n";
            cout<<s<<"\n";
        }
        else cout<<"NO\n";
    }
}