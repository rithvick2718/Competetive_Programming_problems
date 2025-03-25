#include<bits/stdc++.h>
using namespace std; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    int n,x;
    while(tt--)
    {
        //code
        cin>>n>>x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        sort(a.rbegin(),a.rend());
        int teams=0,last=-1;
        for(int i=0; i<n; i++)
        {
            if(a[i]*(i-last)>=x){
                teams++;
                last=i;
            }
        }
        cout<<teams<<"\n";
    }
}