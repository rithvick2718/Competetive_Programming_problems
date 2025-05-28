#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000001LL
int cnt(const vector<ll> &A, const ll &val){
    ll ans=0;
    for(auto a : A) if(a==val) ans++;
    return ans;
}
ll n_area(const vector<ll> &X,const vector<ll> &Y, ll ex){
    int ct = cnt(X,ex);
    if(ct>1) return ((INF+1LL)*(INF+1LL));
    int n =X.size();
    ll mn_x=INF+1,mn_y=INF+1,mx_x=-1LL,mx_y=-1LL;
    for(int i=0; i<n; i++)
    {
        if(X[i]!=ex){
            mn_x=min(X[i],mn_x);
            mn_y=min(Y[i],mn_y);
            mx_x=max(X[i],mx_x);
            mx_y=max(Y[i],mx_y);
        }
    }
    ll w=(mx_x-mn_x+1);
    ll h=(mx_y-mn_y+1);
    ll area = w*h;
    if(area>n-1) return area;
    else return area+min(w,h);
    return (INF+2LL)*(INF+2LL);
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
        vector<ll> X(n),Y(n);
        ll mn_x=INF,mn_y=INF,mx_x=0LL,mx_y=0LL;
        for(int i=0; i<n; i++)
        {
            cin>>X[i]>>Y[i];
            mn_x=min(X[i],mn_x);
            mn_y=min(Y[i],mn_y);
            mx_x=max(X[i],mx_x);
            mx_y=max(Y[i],mx_y);
        }
        ll ans = (mx_x-mn_x+1)*(mx_y-mn_y+1);
        ans = min(ans,n_area(X,Y,mn_x));
        ans = min(ans,n_area(X,Y,mx_x));
        ans = min(ans,n_area(Y,X,mn_y));
        ans = min(ans,n_area(Y,X,mx_y));
        cout<<ans<<"\n";
    }
}