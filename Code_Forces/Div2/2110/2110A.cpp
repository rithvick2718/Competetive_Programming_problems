#include<bits/stdc++.h>
using namespace std;
int odd_even (vector<int> &a)
{
    int n =a.size();
    int first_odd=-1,first_even=-1,last_odd=-1,last_even=-1;
    for(int i=0; i<n; i++)
    {
        if(a[i]&1){
            first_odd=i;
            break;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(!(a[i]&1)){
            first_even=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        if(a[i]&1){
            last_odd=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        if(!(a[i]&1)){
            last_even=i;
            break;
        }
    }
    int ans=100;
    if(first_even!=-1) ans=min(ans, first_even+n-1-last_even);
    if(first_odd!=-1) ans=min(ans, first_odd+n-1-last_odd);\
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        cout<<odd_even(a)<<"\n";
    }
}