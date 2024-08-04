#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int r,c;
    while(t--)
    {
        if(r>c)
        {
            cout<<r*r-c+1;
        }
    }
}