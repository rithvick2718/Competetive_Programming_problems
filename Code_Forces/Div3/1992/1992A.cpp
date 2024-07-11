#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int a,b,c;
    while(t--)
    {
        cin>>a>>b>>c;
        int mx =INT16_MIN;
        for(int i=0; i<6; i++)
        {
            for(int j=0; i+j <6;j++)
            {
                mx=max(mx,(a+i)*(b+j)*(c+5-i-j));
            }
        }
        cout<<mx<<"\n";
    }
}