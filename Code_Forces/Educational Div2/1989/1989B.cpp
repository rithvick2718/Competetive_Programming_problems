#include<bits/stdc++.h>
#include<string>
using namespace std;
int maximize(string &a, string &b)
{
    int ans =0;
    for(int j=0; j<b.length(); j++)
    {
        int ptr =j;
        for(int i=0; i<a.length();i++)
        {
            if(a[i]==b[ptr]) ptr++;
            if(ptr==b.length()) break;            
        }
        ans = max(ans, ptr -j);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout<<a.length()+b.length()-maximize(a,b)<<"\n";
    }
    return 0;
}