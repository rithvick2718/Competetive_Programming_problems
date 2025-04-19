#include<bits/stdc++.h>
using namespace std;
void print_v(const vector<int> &V)
{
    for(auto v : V) cout<<v<<" ";
    cout<<"\n";
    return;
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
        vector<int> vals;
        int prev,present;
        cin>>prev;
        for(int i=1;i<n;i++){
            cin>>present;
            if(prev!=present) vals.push_back(i);
            prev=present;
        }
        // print_v(vals);
        int q,l,r,x;
        cin>>q;
        while(q--){
            cin>>l>>r;
            auto y=lower_bound(vals.begin(),vals.end(),l);
            if(y!=vals.end()) x=*y;
            else x = 1e7; // this ensures x>r
            if(x+1<=r) cout<<x<<" "<<x+1<<"\n";
            else cout<<-1<<" "<<-1<<"\n";
        }
        cout<<"\n";
    }
}