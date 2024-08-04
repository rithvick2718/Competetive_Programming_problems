#include<bits/stdc++.h>
using namespace std;
unordered_map<char, int> dict;
bool is_valid (const vector<int> &v)
{
    stack<int> st;
    int N=v.size();
    for(int i=0; i<N;i++)
    {
        if(st.empty() )
        {
            if(v[i]%2==0) return false;
            else st.push(v[i]);
        }        
        else if(v[i]%2==0 && v[i]-1 == st.top()) st.pop();
        else if(v[i]%2==1) st.push(v[i]);
        else if(v[i]%2==0 && v[i]-1 != st.top()) return false;
    }
    return(st.empty());
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        string t;
        cin>>t;
        vector<int> v;
        dict['('] =1;
        dict[')'] =2;
        dict['['] =3;
        dict[']'] =4;
        dict['{'] =5;
        dict['}'] =6;
        for(char k : t )
        {
            v.push_back(dict[k]);
        }
        if(is_valid(v)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}