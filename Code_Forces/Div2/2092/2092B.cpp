#include<bits/stdc++.h>
using namespace std;
bool in_range(int x, int n)
{
    return (x>=0) && (x<= n-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code
        int n;
        cin>>n;
        int p=0,q=0;
        char c;
        for(int i=0; i<n; i++)
        {
            cin>>c;
            if((i&1) && (c=='0')) q++;
            else if( c == '0') p++;
        }
        for(int i=0; i<n; i++)
        {
            cin>>c;
            if((i&1) && (c=='0')) p++;
            else if( c == '0') q++;
        }
        int p_break,q_break;
        p_break=n/2;
        q_break=n/2;
        if(n&1) p_break++;
        if(p>=p_break && q>=q_break) cout<<"YES\n";
        else cout<<"NO\n";
    }
}