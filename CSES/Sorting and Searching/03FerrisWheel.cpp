#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int p[n];
    for(int i=0; i<n;i++)
    {
        cin>>p[i];
    }
    sort(p,p+n); //p[i] are all less than
    int low=0,high=n-1;
    int ans=0;
    while(low<high)
    {
        if(p[low]+p[high]>x) high--;
        else{
            ans++;
            low++;
            high--;
        }
    }
    cout<<n-ans;
}