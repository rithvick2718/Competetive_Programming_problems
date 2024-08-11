#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int x,y,k;
    while(t--)
    {
        //code
        cin>>x>>y>>k;
        if(k&1)
        {
            cout<<x<<" "<<y<<"\n";
            int p=1;
            for(int i=1;i<k;i+=2)
            {
                cout<<x-p<<" "<<y+p<<"\n";
                cout<<x+p<<" "<<y-p<<"\n";
                p++;
            }
        }
        else
        {
            int p=1;
            for(int i=0;i<k;i+=2)
            {
                cout<<x-p<<" "<<y+p<<"\n";
                cout<<x+p<<" "<<y-p<<"\n";
                p++;
            }
        }
    }
}