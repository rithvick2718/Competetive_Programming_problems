#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    int l1,l2,l3,b1,b2,b3;
    while(tt--){
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        bool ans = false;
        ans |= ((l1 == l2) && (l2 == l3) && (l1 == b1+b2+b3));
        ans |= ((b1 == b2) && (b2 == b3) && (b1 == l1+l2+l3));
        ans |= ((l2 == l3) && (b1 == b2 + b3) && (l1+l2 == b1));
        ans |= ((b2 == b3) && (l1 == l2 + l3) && (b1+b2 == l1));
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}