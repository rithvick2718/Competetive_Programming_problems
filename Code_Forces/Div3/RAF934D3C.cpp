#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    int x;
    int a;
    while(t--)
    {
        cin>>n;
        a=1001;
        cout<<a<<" ";
        for (int i=0; i<n-1;i++)
        {
            cin>>x;
            a=x%a +a;
            cout<<a<<" ";
        }
    }
}