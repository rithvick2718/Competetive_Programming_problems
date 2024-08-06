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
        int sum=0;
        while(n!=0)
        {
            sum+=(n%10);
            n/=10;
        }
        cout<<sum<<"\n";
    }
}