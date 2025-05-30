#include<bits/stdc++.h>
using namespace std;
#define INF 1e7
vector<int> primes;
int gcd(int x , int y);
void fill_primes();
int largest_prime_that_divides_x (int x); // figure out a better name
int maximize(int x, int k);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill_primes();
    int tt,x,y,k;
    cin>>tt;
    while(tt--){
        cin>>x>>y>>k;
        int g = gcd(x,y);
        x/=g;
        y/=g;
        int px = largest_prime_that_divides_x(x);
        int py = largest_prime_that_divides_x(y);
        if(max(px,py)>k) cout<<-1<<"\n";
        else cout<<maximize(x,k)+maximize(y,k)<<"\n";
    }
}
int gcd(int x , int y)
{
    if(x>=y){
        int r=x%y;
        while(r!=0){
            x=y;
            y=r;
            r=x%y;
        }
        return y;
    }
    return gcd(y,x);
} // valid and efficient
void fill_primes()
{
    bitset<1000'001> is_prime;
    is_prime.set();
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2; i<1000; i++){
        if(is_prime[i])
            for(int j=i*i; j<1000'001; j+=i)
                is_prime[j]=false;
    }
    for(int i=0; i<1000'001; i++) if(is_prime[i]) primes.push_back(i);
    return;
} //valid and efficient
int largest_prime_that_divides_x (int x) // figure out a better name
{
    vector<int>::iterator it = upper_bound(primes.begin(),primes.end(),x); // *it is the first prime p such that p > x, in case of it == primes.end() don't worrry as x < 10^6
    if(it==primes.begin()) return 1;
    --it; // --it is the largest prime such that p <= x
    while(x%(*it)!=0) --it;
    return *it;
} // valid and efficient
int maximize(int x, int k)
{
    // DP!
    // the idea is to calculate maximize(f,k) where f is a factor of x
    if(x==1) return 0;
    vector<int> f,g;
    for(int i=1; i*i<= x; i++){
        if(x%i==0){
            f.push_back(i);
            if(i!=x/i) g.push_back(x/i);
        }
    }
    f.insert(f.end(),g.rbegin(),g.rend());
    int n =f.size();
    vector<int> dp(n,INF);
    for(int i=0; i<n; i++)
    {
        if(f[i]<=k) dp[i]=1;
        else{
            for(int j=0; j<=i; j++){
                if(f[j]<=k && f[i]%f[j]==0){
                    vector<int>::iterator it = lower_bound(f.begin(),f.end(),f[i]/f[j]);
                    int l = distance(f.begin(),it);
                    dp[i]=min(dp[i],1+dp[l]);
                }
            }
        }
    }
    return dp[n-1];
}