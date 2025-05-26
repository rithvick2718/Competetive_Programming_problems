#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        // code
        int n;
        cin>>n;
        bool not_found = true;
        for(int i=0; i<=99; i++){
            if(n==i*i){
                cout<<0<<" "<<i<<"\n";
                not_found=false;
                break;
            }
        }
        if(not_found) cout<<-1<<"\n";
    }
}