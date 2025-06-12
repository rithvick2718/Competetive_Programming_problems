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
        cout<<2*n-3<<"\n";
        for(int i=1; i<n; i++){
            if(1!=i) cout<<i<<" "<<1<<" "<<i<<"\n";
            if(i+1!=n) cout<<i<<" "<<i+1<<" "<<n<<"\n";
        }
        cout<<n<<" "<<1<<" "<<n<<"\n";
     }
}