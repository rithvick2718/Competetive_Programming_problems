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
        //code for each test case
        int n;
        cin>>n;
        int m=0; //upto n-1
        int h;
        for (int i = 0; i < n-1; i++)
        {
            cin>>h;
            if(h>m) m=h;
        }
        cin>>h;
        cout<<m+h<<"\n";
    }
}