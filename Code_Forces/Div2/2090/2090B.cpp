#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n,m;
        cin>>n>>m;
        bool a[n][m];
        char x; 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>x;
                if(x=='0') a[i][j]=false;
                else a[i][j]=true;
            }
        }
        // traverse
        bool r[n],c[m];
        for(int i=0; i<n; i++)
        {
            r[i]=a[i][0];
        }
        for(int j=0; j<m; j++)
        {
            c[j]=a[0][j];
        }
        bool ans=true;
        bool to_break=false;
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(a[i][j]){ //means this is 1
                    if(!(r[i]|c[j])){
                        ans=false;
                        to_break=true;
                        break;
                    }
                    c[j]=c[j]&a[i][j];
                    r[i]=r[i]&a[i][j];
                }
                else
                {
                    r[i]=false;
                    c[j]=false;
                }
            }
            if(to_break) break;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}