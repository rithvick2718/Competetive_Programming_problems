#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        //code for each test case
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n;i++)
        {
            cin>>a[i];
        }
        if(a[0]==a[n-1]) cout<<"NO";
        else
        {
            cout<<"YES\n";
            n=n-2;
            cout<<"RB";
            while(n--)
            {
                cout<<"R";
            }
        }
        cout<<"\n";
    }
}