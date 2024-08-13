#include<bits/stdc++.h>
using namespace std;
int a[200001];
bool ans(string &k , int n)
{
    if(k.length()!=n) return false;
    map<char,int> char_int;
    map<int,char> int_char;
    for(int i=0; i<n; i++)
    {
        if(char_int.count(k[i])==0 && int_char.count(a[i])==0)
        {
            char_int[k[i]]=a[i];
            int_char[a[i]]=k[i];
        }
        else if(char_int[k[i]]!=a[i] || int_char[a[i]]!=k[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        cin>>m;
        string k;
        for(int i=0; i<m ;i++)
        {
            cin>>k;
            if(ans(k,n)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}