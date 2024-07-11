#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        cin>>n>>k;
        int a;
        int mx =INT_MIN;
        int sum=0;
        for(int i=0; i<k; i++)
        {
            cin>>a;
            sum+=2*(a-1)+1;
            mx = max(mx,a);
        }
        cout<<sum-2*(mx)+1<<"\n";
    }
}