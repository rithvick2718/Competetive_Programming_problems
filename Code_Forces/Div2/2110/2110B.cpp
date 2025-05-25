#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    string S;
    while(tt--){
        cin>>S;
        int len = S.length();
        int a = 1, b=0;
        for(int i=1; i<len; i++){
            if(S[i]=='(') a++;
            else b++;
            if(a==b) break;
        }
        if(a+b != len) cout<<"YES\n";
        else cout<<"NO\n";
    }
}