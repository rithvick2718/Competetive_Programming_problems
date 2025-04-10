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
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        vector<bool> b(n,false);
        for(int i=0; i<n; i++) cin>>a[i];
        string input;
        int mx=0,cnt,tcnt=0;
        for (int i = 0; i < m; i++)
        {
            cnt=0;
            for (int j = 0; j < n; j++)
            {
                cin>>input;
                if(a[j]==input) {
                    cnt++;
                    if(!b[j]){
                        tcnt++;
                        b[j]=true;
                    }
                }
            }
            mx=max(mx,cnt);
        }
        if(tcnt==n) cout<<3*n-2*mx<<"\n";
        else cout<<-1<<"\n";
    }
}