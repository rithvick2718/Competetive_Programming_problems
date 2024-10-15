#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin>>n>>s;
    int a[26]={};
    int ans=0;
    for(int i=0; i<2*n-2;i++)
    {
        if(!(i&1)) a[s[i]-'a']++;
        else{
            if(a[s[i]-'A']>0) a[s[i]-'A']--;
            else ans++;
        }
    }
    cout<<ans<<"\n";
}