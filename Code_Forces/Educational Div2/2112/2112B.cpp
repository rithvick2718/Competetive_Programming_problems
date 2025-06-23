#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        int count =0;
        for(int i=0;i<n-1; i++){
            if(abs(a[i]-a[i+1])==1 || a[i]==a[i+1]) count++;
        }
        if(count !=0) cout<<0<<"\n";
        else{
            bool is_strictly_inc =true;
            bool is_strictly_dec =true;
            for(int i=0; i<n-1; i++){
                is_strictly_inc &= (a[i]<a[i+1]); 
                is_strictly_dec &= (a[i]>a[i+1]); 
            }
            if(is_strictly_dec || is_strictly_inc) cout<<-1<<"\n";
            else cout<<1<<"\n";
        }
    }
}