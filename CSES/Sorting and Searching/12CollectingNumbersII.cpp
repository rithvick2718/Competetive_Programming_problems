#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_set<int> make_fronts(int x, int y, int b[])
{
    unordered_set<int> fronts;
    if(b[x-1]+1<n) fronts.insert(b[x-1]);
    if(b[x-1]>0) fronts.insert(b[x-1]-1);
    if(b[y-1]+1<n) fronts.insert(b[y-1]);
    if(b[y-1]>0) fronts.insert(b[y-1]-1);
    return fronts;
}
int contribute(unordered_set<int> &S, int a[])
{
    int c=0;
    for(auto s:S)
    {
        if(a[s]>a[s+1]) c++;
    }
    return c;
}
int change(int x, int y, int a[], int b[])
{
    unordered_set<int> mf=make_fronts(x,y,b);
    int c1=contribute(mf,a);
    swap(b[x-1],b[y-1]);
    a[b[x-1]]=x-1;
    a[b[y-1]]=y-1;
    int c2=contribute(mf,a);
    return c2-c1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin>>n>>m;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++)
    {
        cin>>x;
        a[x-1]=i;
        b[i]=x-1;
        //a[b[i]]=i
    }
    int ans=1;
    for (int i = 1; i < n; i++)
    {
        if(a[i-1]>a[i]) ans++;
    }
    while(m--)
    {
        cin>>x>>y;
        ans+=change(x,y,a,b);
        cout<<ans<<"\n";
    }
}