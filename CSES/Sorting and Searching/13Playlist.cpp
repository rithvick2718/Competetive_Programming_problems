#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    //the main idea is we have a start and end.
    // in the next iteration we see that if the element next to end that is a[end+1] occurs from a[start] to a[end]
    int start=0,end=0;
    int mx=1;
    map<int,int> mp;
    mp[a[0]]=1;
    while(end+1<n) //come back
    {
        mx=max(end-start+1,mx);
        if(mp[a[end+1]]<start+1){
            end++;
            mp[a[end]]=end+1;
        }
        else{
            start=mp[a[end+1]];
            end++;
            mp[a[end]]=end+1;
        }
        mx=max(end-start+1,mx);
    }
    cout<<mx;
}