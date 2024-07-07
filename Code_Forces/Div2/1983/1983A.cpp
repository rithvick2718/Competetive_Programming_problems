#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        //code for each testcase
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cout<<2*(i+1)<<" ";
        }
        cout<<"\n";
    }
}