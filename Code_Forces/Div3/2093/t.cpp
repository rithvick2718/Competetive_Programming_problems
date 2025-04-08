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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long arr[16][16];
    pair<int,int> t;
    for (long long d = 1; d < 257; d++)
    {
        t=d_to_xy(d);
        // cout<<d<<" : "<<t.first<<" "<<t.second<<"\n";
        arr[t.first-1][t.second-1]=d;
    }
    cout<<d_to_xy(256).first<<" "<<d_to_xy(256).second<<" ";
    ofstream cout;
    cout.open("out.txt");
    for(int i=0;i<16;i++)
    {
        for(int j=0; j<16; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout.close();
}