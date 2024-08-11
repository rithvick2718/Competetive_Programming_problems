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
        int a[n],b[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        bool bob_wins=true;
        if(a[0]==b[0])
        {
            for(int i=0; i<n && bob_wins;i++)
            {
                bob_wins=(a[i]==b[i]);
            }
        }
        else if(a[0]==b[n-1])
        {
            for(int i=0; i<n && bob_wins; i++)
            {
                bob_wins=(a[i]==b[n-i-1]);
            }        
        }
        else bob_wins=false;
        if(bob_wins) cout<<"Bob\n";
        else cout<<"Alice\n";
    }
}