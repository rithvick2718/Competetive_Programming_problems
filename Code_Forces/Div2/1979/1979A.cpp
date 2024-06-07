#include<bits/stdc++.h>
using namespace std;
int mc(vector<int> &a, int &i, int &j)
{
    int m= a[i];
    for(int t = i; t<=j;t++)
    {
        m=max(a[t],m);
    }
    return(m);
}
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
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int size = a.size();
        int m=std::numeric_limits<int>::max();
        for(int i=0; i< size-1; i++)
        {
            m=min(m,max(a[i],a[i+1]));
        }
        cout<<m-1<<"\n";
    }
}