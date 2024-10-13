#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        a[x-1]=i;
    }
    x=1;
    for (int i = 1; i < n; i++)
    {
        if(a[i-1]>a[i]) x++;
    }
    cout<<x;
}