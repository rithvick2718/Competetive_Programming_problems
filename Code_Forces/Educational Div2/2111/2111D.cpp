#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<int> a(m);
        for(int i=0; i<m; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int low=0,high=m-1;
        for(int i=0; i<n; i++){
            if(i&1){
                for(int j=0; j<3; j++){
                    cout<<a[low]<<" "<<a[high]<<" ";
                }
                low++;
                high--;
            }
            else{
                for(int j=0; j<3; j++){
                    cout<<a[high]<<" "<<a[low]<<" ";
                }
            }
            cout<<"\n";
        }
    }
}