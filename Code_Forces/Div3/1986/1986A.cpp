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
        //code for each testcase
        vector<int> x(3);
        cin>>x[0]>>x[1]>>x[2];
        sort(x.begin(),x.end());
        cout<<x[2]-x[0]<<"\n";
    }
}