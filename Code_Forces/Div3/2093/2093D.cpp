#include<bits/stdc++.h>
using namespace std;
int log_4(long long n)
{
    int ans=0;
    long long m=n;
    while(n>0){
        ans++;
        n>>=2;
    }
    if(1LL<<(2*(ans-1))==m) ans--;
    return ans;
} // we get n <= 4^ans
// so 4^(ans-1) < n <= 4^ans
pair<int,int> d_to_xy(long long d)
{
    if(d==1) return{1,1};
    if(d==2) return{2,2};
    if(d==3) return{2,1};
    if(d==4) return{1,2};
    int n= log_4(d)-1;
    long long pwr = 1LL<<(2*n);
    int m= (int) (d/pwr);
    if(d%pwr!=0) m++;
    m=min(m,4); // now m is all right
    pair<int,int> t;
    t=d_to_xy(d-(m-1)*pwr);
    int powr=1<<n;
    if(m==2){
        t.first+=powr;
        t.second+=powr;
    }
    if(m==3){
        t.first+=powr;
    }
    if(m==4){
        t.second+=powr;
    }
    return t;
}
int log_2(int n)
{
    int ans=0;
    int m=n;
    while(n>0)
    {
        ans++;
        n>>=1;
    }
    if(m%(1<<(ans-1))==0) ans--;
    return ans;
}
// we get n <= 2^ans
// so 2^(ans-1) < n <= 2^ans
long long xy_to_d(int x, int y)
{
    if(x==1 && y== 1) return 1;
    if(x==2 && y== 2) return 2;
    if(x==2 && y== 1) return 3;
    if(x==1 && y== 2) return 4;
    int n = log_2(max(x,y));
    int pwr=1<<(n-1);
    if(x > pwr && y > pwr) return (long long)pwr *(long long)pwr + xy_to_d(x-pwr,y-pwr);
    if(x > pwr && y <= pwr) return 2LL*(long long)pwr *(long long)pwr + xy_to_d(x-pwr,y);
    if(x <= pwr && y > pwr) return 3LL*(long long)pwr *(long long)pwr + xy_to_d(x,y-pwr);
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,q;
        cin>>n>>q;
        char c;
        int x,y;
        long long d;
        pair<int,int> t;
        while(q--){
            cin>>c;
            if(c=='-'){
                cin>>c;
                cin>>x>>y;
                cout<<xy_to_d(x,y)<<"\n";
            }
            else{
                cin>>c;
                cin>>d;
                t=d_to_xy(d);
                cout<<t.first<<" "<<t.second<<"\n";
            }
        }
    }
}