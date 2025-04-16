#include<bits/stdc++.h>
using namespace std;
bool check(int x , const vector<int> a, const string &s, int n, int k){
    char last = 'R';
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i]>x){
            if(s[i]=='B' && last=='R'){
                cnt++;
                if(cnt>k) return false;
            }
            last=s[i];
        }
    }
    return cnt<=k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        int l=0,r=1e9;
        int m =l+(r-l)/2;
        int res;
        while(l<=r){
            m =l+(r-l)/2;
            if(check(m,a,s,n,k)) {
                res=m;
                r=m-1;
            }
            else l=m+1;
        }
        cout<<res<<"\n";
    }
}