#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>

string solve(const std::string &S) {
    string ans;
    int n = S.length();
    bool there[n];
    vector<int> lower;
    vector<int> upper;
    fill(there, there + n, true);
    for(int i=0; i<n; i++)
    {
        if(S[i]!='b' && S[i]!='B')
        {
            if(S[i]>='a' && S[i] <= 'z') lower.push_back(i);
            else upper.push_back(i);
        }
        else
        {
            there[i]=false;
            if(S[i]=='b' && lower.size()!=0){
                there[lower.back()]=false;
                lower.erase(lower.end()-1);
            }
            if(S[i]=='B' && upper.size()!=0){
                there[upper.back()]=false;
                upper.erase(upper.end()-1);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(there[i]) ans.push_back(S[i]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string s;
    while (t--)
    {
        cin>>s;
        cout<<solve(s)<<"\n";
    }
}