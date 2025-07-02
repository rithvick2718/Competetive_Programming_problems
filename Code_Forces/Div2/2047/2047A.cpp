#include<bits/stdc++.h>
using namespace std;
bool check_this_sum(int sum){
    int k = sqrt(sum);
    if(k*k == sum && k%2==1) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int a;
        int sum = 0;
        int ans=0;
        for(int i=0 ; i<n ; i++){
            cin>>a;
            sum+=a;
            if(check_this_sum(sum)) ans++;
        }
        cout<<ans<<"\n";
    }
}