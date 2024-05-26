#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x; //fine
    int y; //fine
    while(t--)
    {
        cin>>x>>y;
        int s = (y)/2 +(y%2); //these boxes are must
        if(7*s>x) cout<<s<<"\n";
        else
        {
            x=x-7*s; //these are the extras
            if(y%2==0) //there were even boxes
            {
                s=s+(x)/15;
                if(x%15!=0) s++;
            } //fine
            else
            {
                if(x>4)
                {
                    x=x-4;
                    s=s+(x)/15;
                    if(x%15!=0) s++;
                }
            }
            cout<<s<<"\n";
        }
    }
}