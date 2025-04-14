#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,set<int>> mp;
vector<int> divisors(int k) //fine
{
    if(k==1) return {};
    vector<int> v1,v2;
    for(int i=2; i*i<=k; i++)
    {
        if(k%i==0){
            v1.push_back(i);
            if(i!=k/i) v2.push_back(k/i);
        }
    }
    for(int i=v2.size()-1; i>=0; i--){
        v1.push_back(v2[i]);
    }
    v1.push_back(k);
    return v1;
} // O(srqt(k))
int reduce(int k, int d) // fine
{
    if(d==0) return -1;
    if(d==1) return k;
    while(k%d==0) k/=d;
    return k;
}
ll f(int k, int l, int r)
{
    if(l>r) return 0LL;
    if(k==1) return (ll)(r-l+1);
    vector<int> D=divisors(k); // this won't be empty a k!=1
    pair<int,int> pos_div={1e7,-1};
    for(auto d : D){
        if(!mp[d].empty()){
            auto it = mp[d].lower_bound(l);
            if(*it <= r && pos_div.first > *it && it!=mp[d].end() ){
                pos_div={*it,d};
            }
        }
    }
    if(pos_div.second!=-1){
        ll ans=((ll)(pos_div.first-l))*((ll)k);
        k=reduce(k,pos_div.second);
        return ans+k+f(k,pos_div.first+1,r);
    }
    return ((ll)k)*((ll)(r-l+1));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,q,a;
        cin>>n>>q;
        mp.clear();
        for(int i=0; i<n; i++){
            cin>>a;
            mp[a].insert(i+1);
        }
        int k,l,r;
        while(q--){
            cin>>k>>l>>r;
            cout<<f(k,l,r)<<"\n";
        }
    }
}