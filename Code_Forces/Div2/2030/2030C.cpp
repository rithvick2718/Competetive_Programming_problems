#include<bits/stdc++.h>
using namespace std;
bool cont_one(string &s)
{
    for(int i=0; i<s.length()-1; i++)
    {
        if(s[i]=='1' && s[i+1]=='1') return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    string s;
    while (t--) {
        cin >> n;
        cin >> s;
        if(s[0]=='1' || s[n-1]=='1') cout<<"YES\n";
        else
        {
            bool cont=cont_one(s);
            if(cont) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}