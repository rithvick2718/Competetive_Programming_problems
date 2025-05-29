#include<bits/stdc++.h>
using namespace std;
vector<int> primes; // I store all the primes at once.
void fill_primes(); // the function to store them
int gcd(int x, int y);
pair<int,int> largest_prime(int x); // stores the largest prime that divides x and the index of the prime in vector<int> primes
void fill_primes()
{
    vector<bool> is_prime(1e6+1,true);
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2; i<=1'000; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=1e6; j+=i){
                is_prime[j]=false;
            }
        }
    }
    for(int i=0; i<1e6+1; i++) if(is_prime[i]) primes.push_back(i);
    return;
}
int gcd(int x, int y)
{
    if(x>=y){
        int r=x%y;
        while(r!=0)
        {
            x=y;
            y=r;
            r=x%y;
        }
        return y;
    }
    return gcd(y,x);
}
pair<int,int> largest_prime(int x)
{
    vector<int>::iterator it =  upper_bound(primes.begin(),primes.end(),x);
    if (it == primes.begin()) return {1,0}; // x<2
    --it;
    while(x%(*it)!=0) --it;
    return {*it,it-primes.begin()}; // so I return the largest prime that divides x
}

int reduction(int x, int index_of_largest_prime_dividing_x, int k)
{
    if(x==1) return 0;
    vector<pair<int,int>> primes_dividing_x;
    int power_of_prime;
    int sum_of_powers=0;
    for(int i=0; i<=index_of_largest_prime_dividing_x; i++)//making up primes_dividing_x
    {
        power_of_prime=0;
        while(x%primes[i]==0){
            power_of_prime++;
            sum_of_powers++;
            x/=primes[i];
        }
        if(power_of_prime!=0) primes_dividing_x.push_back({primes[i],power_of_prime});
    }
    // now we reduce vector<pair<int,int>> primes_dividing_x;
    int t=1;
    int ans=0;
    while(sum_of_powers>0){ // in each look we remove a specific t from x.
        int i=primes_dividing_x.size()-1;
        t=1;
        while(i>=0){
            if(primes_dividing_x[i].second>0 && t*primes_dividing_x[i].first<=k){
                t*=primes_dividing_x[i].first;
                primes_dividing_x[i].second--;
                sum_of_powers--;
            }
            else i--;
        }
        ans++;
    }
    return ans;
}
int main()
{
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
        pair<int,int> px = largest_prime(x);
        pair<int,int> py = largest_prime(y);
        if(max(px.first,py.first)>k) cout<<"-1\n";
        else{
            cout<<reduction(x,px.second,k)+reduction(y,py.second,k)<<"\n";
        }
    }
}