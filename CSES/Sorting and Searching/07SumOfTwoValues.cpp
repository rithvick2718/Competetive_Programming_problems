#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    pair<int,int> a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    int low=0,high=n-1;
    while(low<high && a[low].first+a[high].first!=x)
    {
        if(a[low].first+a[high].first>x) high--;
        else low++;
    }
    if(low!=high && a[low].first+a[high].first==x) cout<<a[low].second<<" "<<a[high].second;
    else cout<<"IMPOSSIBLE";
}