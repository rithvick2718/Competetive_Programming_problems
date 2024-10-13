#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long x[n];
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
    }
    sort(x,x+n);
    long long current_sum=1;
    for(int i=0; i<n; i++)
    {
        if(current_sum<x[i]) break;
        current_sum+=x[i];
    }
    cout<<current_sum;
}