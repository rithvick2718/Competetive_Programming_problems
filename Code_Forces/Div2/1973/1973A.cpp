#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases must take
    cin>>t;
    int p1,p2,p3; //points of players must
    while(t--)
    {
        cin>>p1>>p2>>p3; //now (p1+p2+p3)/2 is total matches played
        if((p1+p2+p3)%2 == 1)
        {
            cout<<-1<<"\n";
        }
        else
        {
            if(p1+p2-p3<0)
            {
                cout<<p1+p2<<"\n";
            }
            else
            {
                cout<<((p1+p2+p3)/2)<<"\n";
            }
        }
    }
}