#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n;
    cin>>tt;
    while(tt--){
        cin>>n;
        vector<int> a(n);
        vector<bool> b(n,false);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            a[i]--;
        }
        int j,c,ans=0;
        for(int i=0; i<n; i++)
        {
            c=0;
            if(!b[i])
            {
                b[i]=true;
                j=i;
                while (i!=a[j])
                {
                    b[a[j]]=true;
                    j=a[j];
                    c++;
                }
            }
            ans+=c/2;
        }
        cout<<ans<<"\n";
    }
}