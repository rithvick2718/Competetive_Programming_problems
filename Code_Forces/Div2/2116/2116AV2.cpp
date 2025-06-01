#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,a,b,c,d,mn;
    cin>>tt;
    while(tt--){
        cin>>a>>b>>c>>d;
        mn = min({a,b,c,d});
        if(mn==b || mn == d) cout<<"Gellyfish\n";
        else cout<<"Flower\n";
    }
}