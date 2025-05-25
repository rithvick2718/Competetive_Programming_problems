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
        vector<int> a(n);
        for(int i=0; i<n; i++) 
            cin>>a[i];
        sort(a.begin(),a.end());
        int f_e=-1,f_o=-1,l_e=-1,l_o=-1;
        for(int i=0; i<n; i++){
            if(a[i]&1){
                f_o=i;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(!(a[i]&1)){
                f_e=i;
                break;
            }
        }
        int ans=100;
        if(f_e!=-1){
            for(int i=n-1; i>=0; i--){
                if(!(a[i]&1)){
                    l_e=i;
                    break;
                }
            }
            ans=min(ans,f_e+n-1-l_e);
        }
        if(f_o!=-1){
            for(int i=n-1; i>=0; i--){
                if(a[i]&1){
                    l_o=i;
                    break;
                }
            }
            ans=min(ans,f_o+n-1-l_o);
        }
        cout<<ans<<"\n";
    }
}