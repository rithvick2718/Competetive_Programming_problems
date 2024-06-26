#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //test cases
    cin>>t;
    while(t--)
    {
        //code
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x2<y1) cout<<"YES\n";
        else if(y2<x1) cout<<"YES\n";
        else if (x1<y1 && x2<y2) cout<<"YES\n";
        else if (y1<x1 && y2<x2) cout<<"YES\n";\
        else cout<<"NO\n";
    }
}