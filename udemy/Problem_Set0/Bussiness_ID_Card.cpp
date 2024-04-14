#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string k;
    int a,b,c,d;
    while(t--)
    {
        cin>>k;
        a=k[0]-'0';
        b=k[1]-'0';
        c=k[2]-'0';
        d=k[3]-'A';
        if((a*b*c)%26 == d) cout<<"AUTHENTIC\n";
        else cout<<"FAKE\n";
    }
}