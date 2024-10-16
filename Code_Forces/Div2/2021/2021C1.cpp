#include<bits/stdc++.h>
using namespace std;
bool is_good_presentation(int a[], int b[], int n, int m)
{
    if(a[0]!=b[0]) return false;
    set<int> used;
    used.insert(a[0]);
    int j=0;
    for(int i=0; i<m; i++)
    {
        if(a[j]==b[i]) used.insert(a[j]);
        else if(j+1<n && a[j+1]==b[i]){
            j++;
            used.insert(a[j]);
        }
        else
        {
            if(used.count(b[i])==0) return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,m,q;
    while(t--)
    {
        cin>>n>>m>>q; //q=0;
        int a[n];
        int b[m];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<m; i++)
        {
            cin>>b[i];
        }
        if(is_good_presentation(a,b,n,m)) cout<<"YA\n";
        else cout<<"TIDAK\n";
    }
}