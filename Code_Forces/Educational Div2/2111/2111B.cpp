#include<bits/stdc++.h>
using namespace std;
vector<int> fib_num(11);
void fill_fib_num()
{
    fib_num[0]=1;
    fib_num[1]=2;
    for(int i=2; i<11; i++){
        fib_num[i]=fib_num[i-1]+fib_num[i-2];
    }
    return;
}
bool does_fit(const int &n, const int &w, const int &l, const int &h){
    int mn = min({w,l,h});
    if(mn<fib_num[n]) return false;
    int mx = max({w,l,h});
    if(mx>=fib_num[n+1]) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    fill_fib_num();
    while(tt--){
        //code
        int n,m,w,l,h;
        cin>>n>>m;
        n--;
        while(m--){
            cin>>w>>l>>h;
            if(does_fit(n,w,l,h)) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
    }
}