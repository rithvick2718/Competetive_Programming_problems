#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    unsigned long long r,c;
    while(t--)
    {
        cin>>c>>r;
        if(r>c)
        {
            if(r&1)
            {
                cout<<r*r-c+1<<"\n";
            }
            else
            {
                cout<<r*r-2*r+2+c-1<<"\n";
            }
        }
        else if(r<c)
        {
            if(c&1)
            {
                cout<<c*c-2*c+2+r-1<<"\n";
            }
            else
            {
                cout<<c*c-r+1<<"\n";
            }
        }
        else
        {
            cout<<c*c-c+1<<"\n";
        }
    }
}