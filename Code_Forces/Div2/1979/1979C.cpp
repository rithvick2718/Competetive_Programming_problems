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
        cin>>n;
        long long int k[n];
        long long int x[n];
        long long int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>k[i];
            x[i]=((long long int)232792560)/k[i];
            sum=sum+x[i];
        }
        if(sum>(long long int)232792539) cout<<-1<<"\n";
        else
        {
            for(int i =0; i<n; i++)
            {
                cout<<x[i]<<" ";
            }
            cout<<"\n";
        }
    }
}