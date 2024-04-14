#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q,a,b,c;
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>c;
        cout<<(b+c)/a<<"\n";
    }
}