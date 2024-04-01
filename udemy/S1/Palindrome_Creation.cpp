#include<bits/stdc++.h>
using namespace std;
int count(string str)
{
    int n,s;
    s=0;
    n=str.size();
    for(int i=0;i<n/2;i++)
    {
        if(str[i]!=str[n-1-i]) s++;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin>>w;
    string str;
    while(w--)
    {
        cin>>str;
        cout<<count(str)<<"\n";
    }
}