#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
void print_v(const vector<int> &V){
for(auto v: V) cout<<v<<" ";
cout<<"\n";
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
int largest_prime(int x)
{
    int prev=x;
    while(x%2==0) {
        prev=x;
        x/=2;
    }
    while(x%3==0){
        prev=x;
        x/=3;
    }
    while(x%5==0){
        prev=x;
        x/=5;
    }
    int i=1;
    while(x>1){
        if((6*i+1)*(6*i+1)>x) return x;
        while(x%(6*i+1)==0){
            prev=x;
            x/=(6*i+1);
        }
        while(x%(6*i+5)==0){
            prev=x;
            x/=(6*i+5);
        }
        i++;
    }
    return prev;
}
vector<int> factors (int x, int k){
    if(x==1) return {};
    vector<int> f,g;
    if(x<=k) g.push_back(x);
    for(int i=2; i*i<=x; i++){
        if(x%i == 0){
            if(i<=k) f.push_back(i);
            if(i!=x/i && x/i<=k) g.push_back(x/i);
        }
    }
    f.insert(f.end(),g.rbegin(),g.rend());
    return f;
} // fine
int reduction(int x,int k){
    if(x==1) return 0;
    cout<<"REDUCING "<<x<<" with factors less than equal to "<<k<<"\n";
    vector<int> f = factors(x,k);
    cout<<"Factors "; print_v(f);
    int ans=0;
    while(x>1){
        int i=f.size()-1;
        while(x%f[i]!=0) i--;
        cout<<x<<"/"<<f[i]<<"\n";
        x/=f[i];
        ans++;
    }
    return ans;
}
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
int no_of_factors(int x){
    int ans=1;
    int s=0;
    for(auto prime : primes){
        s=0;
        while(x%prime==0){
            s++;
            x/=prime;
        }
        ans*=1+s;
        if(x==1) return ans;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill_primes();
    cout<<primes.size();
    int a,b,mx=0;
    for(int i=2; i<1000'001; i++){
        b=no_of_factors(i);
        if(b>mx) a=i;
        mx=max(mx,b);
    }
    cout<<a<<" "<<mx;
}