#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    while(t--)
    {
        int n; //lebngth of array
        cin>>n; //take it's vaalue
        int a; //the element of array
        cin>>a;
        int mx =a;
        int mxd=0;
        long long cost=0;
        for(int i=1; i<n; i++)
        {
            cin>>a;
            if(a>mx) mx=a;
            if(mx-a>mxd) mxd =mx-a;
            cost+=mx-a;
        }
        cost+=mxd;
        cout<<cost<<"\n";
    }
} //so a long long was the problem in this