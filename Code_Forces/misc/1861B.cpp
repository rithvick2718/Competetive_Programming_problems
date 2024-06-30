#include<bits/stdc++.h>
using namespace std;
bool solve(string &a, string &b)
{
    if(a==b) return true;
    // see we know last and first digit are 0 and 1
    int n =a.length();
    int count =0;
    for(int i=0; i<n-1; i++)
    {
        if(a[i]==b[i] && a[i+1]==b[i+1] && a[i]=='0' && a[i+1]=='1') count ++;
        if(count > 0) return true; 
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string a;
    string b;
    while(t--)
    {
        cin>>a; //the start and end of a and b are 0 and 1 respectively 
        cin>>b;
        if(solve(a,b)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}