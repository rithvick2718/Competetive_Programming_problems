#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    // ifstream cin;
    // cin.open("16.in");
    cin>>n>>m>>k;
    int a[n+1];
    int b[m];
    bool occupied[n]={};
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    // cin.close();
    sort(a,a+n);
    sort(b,b+m);
    int ans=0;
    int j=0;
    int last=-1;
    int mn;
    for(int i=0; i<m && j<=n; i++)
    {
        mn=max(0,last);
        j=lower_bound(a+mn,a+n,b[i]-k)-a; //now j is the best person to give the apartment
        while(b[i]>=a[j]-k && j<n)
        {
            if(b[i]<=a[j]+k && a[j]-k<=b[i] && j!=last){
                ans++;
                last=j;
                break;
            }
            j++;
        }
    }
    cout<<ans;
}
