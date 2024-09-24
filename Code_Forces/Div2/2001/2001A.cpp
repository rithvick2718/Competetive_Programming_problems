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
        int a;
        int b[n]={};
        for(int i=0; i<n; i++)
        {
            cin>>a;
            b[a-1]++;
        }
        cout<<n-*max_element(b,b+n)<<"\n";
    }
}