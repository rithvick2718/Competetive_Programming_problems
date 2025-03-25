#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e7 + 1;
vector<bool> is_prime(MAX_N, true);
vector<int> primes;
void precompute_sieve() {
    is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime
    for (int i = 2; i * i < MAX_N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_N; j += i)
                is_prime[j] = false;
        }
    }
    // Store primes in a separate list for fast access
    for (int i = 2; i < MAX_N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_sieve();
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code 
        int n,g;
        cin>>n;
        int ans=0;
        for(int i = 0; i < primes.size() && primes[i] <= n; i++)
        {
            g=n/primes[i];
            ans+=g;
        }
        cout<<ans<<"\n";
    }
}