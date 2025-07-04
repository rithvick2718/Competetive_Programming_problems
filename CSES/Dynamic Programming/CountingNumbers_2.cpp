#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll pwr(ll a, int e);
ll count (ll a);
int between (int low, int high, int exclude);

ll pwr(ll a, int e){
    ll ans = 1LL;
    ll ToMultiply = a;
    while(e>0){
        if(e&1) ans*=ToMultiply;
        ToMultiply*=ToMultiply;
        e>>=1;
    }
    return ans;
}

ll count (ll a){
    if(a<0) return 0LL;
    if(a==0) return 1LL;
    ll ans =0;
    vector<int> A;
    while(a>0){
        A.push_back((int)(a%10LL));
        a/=10LL;
    }
    int n = A.size();
    reverse(A.begin(),A.end());
    ans += ((ll)(A[0]))*pwr(9LL,n-1);
    if(n>2) ans += (pwr(9LL,n-1)-1LL)/8LL;
    for(int i=1; i<n; i++){
        if(i>=2 && A[i-2] == A[i-1]) break; // numbers that are like A[0]A[1]...A[i-1]
        ans += ((ll)(between(-1,A[i],A[i-1])))*pwr(9LL,n-i-1);
    }
    bool add_one = true;
    if(n == 1) add_one = true;
    else{
        for(int i=1; i<n; i++) add_one&=(A[i-1]!=A[i]);
    }
    if(add_one) ans++;
    return ans;
}

int between(int low, int high, int exclude){
    int ans =0;
    for(int i=0; i<10; i++){
        if( low<i && i<high && i!=exclude) ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    cout<<count(b)-count(a-1)<<"\n";
}