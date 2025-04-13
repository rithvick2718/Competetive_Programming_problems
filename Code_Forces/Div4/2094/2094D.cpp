#include<bits/stdc++.h>
using namespace std;
vector<int> makevector(string &S)
{
    vector<int> v;
    char c=S[0];
    int val=0;
    for(auto s :S)
    {
        if(s==c) {
            val++;
        }
        else{
            v.push_back(val);
            val=1;
            c=s;
        }
    }
    v.push_back(val);
    return v;
}
bool check(vector<int> &p, vector<int> &s )
{
    if(p.size()!=s.size()) return false;
    for(int i=0; i<p.size(); i++)
    {
        if(s[i]<p[i] || s[i]>2*p[i]) return false;
    }
    return true;
}
void print_V(vector<int> &p)
{
    for(auto P :p) cout<<P<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code
        string p,s;
        cin>>p>>s;
        if(p[0]!=s[0])cout<<"NO\n";
        else{
            vector<int> P=makevector(p);
            vector<int> S=makevector(s);
            // print_V(P);
            // print_V(S);
            if(check(P,S)) cout<<"YES\n";
            else cout<<"NO\n";            
        }
    }
}