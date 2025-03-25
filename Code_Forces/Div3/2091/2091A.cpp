#include<bits/stdc++.h>
using namespace std; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code
        int n,m,ans=0;
        cin>>n;
        int a[]={0,0,0,0,0};
        int i=0;
        for(; i<n; i++)
        {
            cin>>m;
            if(m==0) a[0]=min(3,a[0]+1);
            if(m==1) a[1]=min(1,a[1]+1);
            if(m==2) a[2]=min(2,a[2]+1);
            if(m==3) a[3]=min(1,a[3]+1);
            if(m==5) a[4]=min(1,a[4]+1);
            if(a[0]+a[1]+a[2]+a[3]+a[4]==8) {
                ans=i+1;
                break;
            }
        }
        while (++i < n) cin >> m;
        cout<<ans<<"\n";
    }
}