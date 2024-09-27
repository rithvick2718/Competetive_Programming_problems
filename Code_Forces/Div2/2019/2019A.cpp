#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n;
        cin>>n;
        int a;
        int mx1=INT_MIN;
        int mx2=INT_MIN;
        int n1=0;
        int n2=0;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            if(i&1)
            {
                if(a>mx1) mx1=a;
                n1++;
            }
            else
            {
                if(a>mx2) mx2=a;
                n2++;
            }
        }
        cout<<max(mx1+n1,mx2+n2)<<"\n";
    }
}