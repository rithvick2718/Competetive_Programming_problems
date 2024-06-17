#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a;
        bool d1 =false; //this checks if there is atleast one 3n+1 element
        int s=0;
        while (n && !d1)
        {
            cin>>a;
            s=(s+a)%3;
            if(a%3==1) d1=true;
            n--;
        }
        while (n)
        {
            cin>>a;
            s=(s+a)%3;
            n--;
        }
        if(s==0) cout<<0<<"\n";
        else if(s==1)
        {
            if(d1) cout<<1<<"\n";
            else cout<<2<<"\n";
        }
        else cout<<1<<"\n";
    }
}