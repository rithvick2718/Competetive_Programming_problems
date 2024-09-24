#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    int n;
    while(t--)
    {
        //code
        cin>>n;
        if(n&1)
        {
            int toprint=n;
            while(toprint>0)
            {
                cout<<toprint<<" ";
                toprint-=2;
            }
            toprint=2;
            while(toprint<n)
            {
                cout<<toprint<<" ";
                toprint+=2;
            }
        }
        else cout<<-1;
        cout<<"\n";
    }
}