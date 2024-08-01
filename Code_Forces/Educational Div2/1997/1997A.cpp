#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        string s;
        cin>>s;
        bool added= false;
        for(int i=1; i< s.length(); i++)
        {
            if(s[i]==s[i-1]) 
            {
                added =true;
                if(s[i]!='z')
                {
                    s.insert(i,1,s[i]+1);
                }
                else s.insert(i,1,s[i]-1);
                break;
            }
        }
        if(added) cout<<s<<"\n";
        else
        {
            char h =s.back();
            if(h!='z')
            {
                h++;
                cout<<s+h<<"\n";
            }
            else{
                h--;
                cout<<s+h<<"\n";
            }
        }
    }
}