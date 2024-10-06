#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        //code
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int x=a[0];
        for(int i=1;i<n;i++)
        {
            x+=a[i];
            x>>=1;
        }
        cout<<x<<"\n";
    }
}