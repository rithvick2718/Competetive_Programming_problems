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
        int n,x;
        cin>>n>>x;
        int mp[n]={};
        int h;
        for(int i=0; i<n; i++)
        {
            cin>>h;
            if(h<n) mp[h]++;
        }
        int j;
        int i=0;
        for(; i<n; i++)
        {
            if(mp[i]==0){
              j=i%x;
              while(j<i){
                if(mp[j]>1){
                    mp[j]--;
                    mp[i]++;
                    break;
                }
                j+=x;
              }
              if(mp[i]==0){
                break;
              }  
            }
        }
        cout<<i<<"\n";
    }
}